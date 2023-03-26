#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_text_button_clicked()
{
    ui->plainTextEdit->selectAll();
    ui->plainTextEdit->copy();
    ui->plainTextEdit_2->paste();
}

void MainWindow::on_replace_button_clicked()
{
    ui->plainTextEdit->selectAll();
    ui->plainTextEdit->copy();
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_2->paste();
}

void MainWindow::on_insert_html_button_clicked()
{
    ui->plainTextEdit_2->appendHtml("<font color='red'>Hello</font>");

}
