#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){

    double D, x1, x2;

    double a = ui->lineEdit->text().toInt();
    double b = ui->lineEdit_2->text().toInt();
    double c = ui->lineEdit_3->text().toInt();

    if(a == 0) {
        x1 = -c/b;
        ui->lineEdit_4->setText(QString("= %1").arg(x1));
        }else {
            D = qPow(b, 2) - 4 * a * c;
            if(D < 0) {
                        ui->lineEdit_4->setText(QString("Нельзя вычислить корень!"));
                        return;
                      }
    x1 = (-b - qSqrt(D)) / 2 * a;
    if(D == 0) ui ->lineEdit_4->setText(QString("x = %1").arg(x1));
    else{
            x2 = (-b + qSqrt(D)) / 2 * a;
            ui->lineEdit_4->setText(QString(" = %1").arg(x1));
            ui->lineEdit_5->setText(QString(" = %2").arg(x2));
        }
    }

}


void MainWindow::on_pushButton_2_pressed()
{
    close();
}

