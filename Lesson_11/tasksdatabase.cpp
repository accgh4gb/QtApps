#include "tasksdatabase.h"
#include "ui_tasksdatabase.h"

tasksDataBase::tasksDataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tasksDataBase)
{
    ui->setupUi(this);

    model = new QSqlQueryModel(this);
    view = new QTableView(this);
    if (!createConnection()) return;
    if (!createTable()) return;
}

tasksDataBase::~tasksDataBase()
{
    delete ui;
}


bool tasksDataBase::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Tasks.db");
    if (!db.open()){
        qDebug() << "Unable to create a connection";
        return false;
    }
    return true;
}

bool tasksDataBase::createTable()
{
    QSqlQuery query;
    QString crtTab =   "CREATE TABLE Tasks ("
                        "id INTEGER PRIMARY KEY NOT NULL,"
                        "task VARCHAR(40),"
                        "date VARCHAR(10),"
                        "progress VARCHAR(2) );";
    if (!query.exec(crtTab)){
        qDebug() << "Unable to create a table";
        return false;
    }
    return true;
}

void tasksDataBase::insData(QString task, QString date, QString progress)
{
    QSqlQuery query;
    QString s = "INSERT INTO Tasks (task, date, progress)"
            "VALUES('%1', '%2', '%3');";
    QString str = s.arg(task).arg(date).arg(progress);
    if (!query.exec(str)){
        qDebug() << "Unable to insert record";
    }
}

void tasksDataBase::printTable()
{
    model->setQuery("SELECT * FROM TASKS ;");
    view->setMinimumWidth(400);
    view->setModel(model);
    show();
}

int tasksDataBase::getCount()
{
    QSqlQuery query;
    QString str = "SELECT COUNT (*) FROM TASKS;";
    query.exec(str);
    query.first();
    return query.value(0).toInt();
}
