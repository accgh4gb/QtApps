#include "mythread.h"

#include <QDirIterator>

myThread::myThread(QStringList name, QString newPath, QDir curDir) : fileNames(name), path(newPath), currentDir(curDir)
{}

void myThread::run()
{
    QDirIterator it(path, fileNames, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    path = it.next();
    emit result(path);
}
