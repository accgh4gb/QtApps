#ifndef TASKS_H
#define TASKS_H

#include <QApplication>
#include <QObject>
#include <QDir>
#include <QFile>
#include <QFileDialog>

class Tasks : public QObject
{
    Q_OBJECT
public:
    explicit Tasks(QObject *parent = nullptr);
    virtual ~Tasks();
    Q_INVOKABLE void addTask(QString);
    void save_as();
    void open();

private:
    QWidget *widget;
    QString task;
    QFile file;
};

#endif // TASKS_H
