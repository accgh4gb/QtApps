#ifndef TASKS_H
#define TASKS_H

#include <QApplication>
#include <QObject>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include "tasksdatabase.h"

class Tasks : public QObject
{
    Q_OBJECT
public:
    explicit Tasks(QObject *parent = nullptr);
    virtual ~Tasks();
    Q_INVOKABLE void addTask(QString task, QString date, QString progress);
    Q_INVOKABLE int getNumOfTasks();
    Q_INVOKABLE void printTable();

private:
    QWidget *widget;
    QString task;
    int numOfTasks = 0;
    tasksDataBase tskDb;
};

#endif // TASKS_H
