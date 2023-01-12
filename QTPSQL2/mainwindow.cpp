#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./data2.db");
    if(db.open())
    {
        qDebug("open");
    } else
    {
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    //query->exec("CREATE TABLE messages(date DATE, time TIME, sender TEXT, message TEXT)");
    model= new QSqlTableModel(this, db);
    model->setTable("messages");
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

