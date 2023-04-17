#include "ref.h"
#include "ui_ref.h"
#include <QFile>

ref::ref(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ref)
{
    ui->setupUi(this);

    QString path = ":/other/ref/ref.txt";
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)){
    QByteArray ba = file.readAll();
    QString text(ba);
    ui->label->setText(text);
    }
}

ref::~ref()
{
    delete ui;
}
