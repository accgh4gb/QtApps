#ifndef TASKSDATABASE_H
#define TASKSDATABASE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QDebug>

namespace Ui {
class tasksDataBase;
}

class tasksDataBase : public QDialog
{
    Q_OBJECT

public:
    explicit tasksDataBase(QWidget *parent = nullptr);
    ~tasksDataBase();

    bool createConnection();

    bool createTable();

    void insData(QString task, QString date, QString progress);

    void printTable();

    int getCount();

private:
    Ui::tasksDataBase *ui;

    QSqlDatabase db;
    QSqlQueryModel *model;
    QTableView *view;
    QString currentTableName;
};

#endif // TASKSDATABASE_H
