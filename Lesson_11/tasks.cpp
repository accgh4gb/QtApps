#include "tasks.h"

Tasks::Tasks(QObject *parent) : QObject {parent}
{
    widget = new QWidget;
}

Tasks::~Tasks()
{

}

void Tasks::addTask(QString task, QString date, QString progress)
{
    tskDb.insData(task, date, progress);
}

int Tasks::getNumOfTasks()
{
    tskDb.getCount();
}

void Tasks::printTable()
{
    tskDb.printTable();
}

