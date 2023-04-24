#include "tasks.h"

Tasks::Tasks(QObject *parent) : QObject {parent}
{
    widget = new QWidget;
    open();
}

Tasks::~Tasks()
{
    save_as();
}

void Tasks::addTask(QString newTask)
{
    task += newTask + '\n';
}


void Tasks::save_as()
{
    QString fileName = QFileDialog::getSaveFileName(widget,
                                                    "Сохранить",
                                                    QDir::currentPath(),
                                                    "Текст (*.txt);;Любой (*.*)");

    file.setFileName(fileName);
    if(file.open(QIODevice::WriteOnly))
    {
        QString text = task;
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.length());
        file.close();
    }
}

void Tasks::open()
{
    QString fileName = QFileDialog::getOpenFileName(widget, "Open file", QDir::currentPath(), "Text (*.txt);;All files (*.*)");

    file.setFileName(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        task = (file.readAll());
        file.close();
    }
}

