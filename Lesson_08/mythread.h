#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QDir>
#include <QObject>
#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread(QStringList name, QString newPath, QDir curDir);
    void run() override;

signals:
    void result(QString);

private:
    QStringList fileNames;
    QString path;
    QDir currentDir;
};

#endif // MYTHREAD_H
