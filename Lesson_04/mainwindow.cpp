#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->OpenFile, &QAction::triggered, this, &MainWindow::OpenFile);
    connect(ui->SaveFile, &QAction::triggered, this, &MainWindow::SaveFile);
    connect(ui->OpenRef, &QAction::triggered, this, &MainWindow::OpenRef);
    connect(ui->LangToRus, &QAction::triggered, this, &MainWindow::LangToRus);
    connect(ui->LangToEng, &QAction::triggered, this, &MainWindow::LangToEng);
    connect(ui->OpenReadOnly, &QAction::triggered, this, &MainWindow::OpenReadOnly);
    connect(ui->CreateFile, &QAction::triggered, this, &MainWindow::CreateFile);
    connect(ui->QuitAction, &QAction::triggered, this, &MainWindow::exit);
    connect(ui->Save, &QAction::triggered, this, &MainWindow::save);

    fillBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if ((event->modifiers() == Qt::CTRL) && (event->key() == Qt::Key_O))
        OpenFile();
    else if ((event->modifiers() == Qt::CTRL) && (event->key() == Qt::Key_N))
        CreateFile();
    else if ((event->modifiers() == Qt::CTRL) && (event->key() == Qt::Key_S))
        SaveFile();
    else if ((event->modifiers() == Qt::CTRL) && (event->key() == Qt::Key_Q))
        exit();
}

void MainWindow::SaveFile()
{
    QString path = QFileDialog::getSaveFileName();
    if (path.isEmpty()) return;
    file.setFileName(path);
    if (file.open(QIODevice::WriteOnly)){
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.length());
        file.close();
    }
}

void MainWindow::OpenRef()
{
    ref window;
    window.setModal(true);
    window.exec();
}

void MainWindow::LangToRus()
{
    translator.load(":/langs/QLanguage_ru.qm");
    QCoreApplication::removeTranslator(&translator);
    QCoreApplication::installTranslator(&translator);
    ui->retranslateUi(this);
    fillBox();
}

void MainWindow::LangToEng()
{
    translator.load(":/langs/QLanguage_en.qm");
    QCoreApplication::removeTranslator(&translator);
    QCoreApplication::installTranslator(&translator);
    ui->retranslateUi(this);
    fillBox();
}

void MainWindow::OpenReadOnly()
{
    ui->plainTextEdit->setReadOnly(true);
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) return;
    file.setFileName(path);
    if (file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        QString text(ba);
        ui->plainTextEdit->setPlainText(text);
    }
}

void MainWindow::OpenFile()
{
    ui->plainTextEdit->setReadOnly(false);
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) return;
    file.setFileName(path);
    if (file.open(QIODevice::ReadWrite)){
        QByteArray ba = file.readAll();
        QString text(ba);
        ui->plainTextEdit->setPlainText(text);
    }
}

void MainWindow::CreateFile()
{
    ui->plainTextEdit->setReadOnly(false);
    ui->plainTextEdit->clear();
}

void MainWindow::exit()
{
    qApp->quit();
}

void MainWindow::fillBox()
{
    actions.clear();
    for(auto action : ui->menu->actions())
    {
        actions.insert(action->text(), action);
    }
    ui->boxActions->clear();
    ui->boxActions->addItems(actions.keys());
}

void MainWindow::on_boxActions_activated(int index)
{
      ui->valHotKey->setText(actions.value(ui->boxActions->itemText(index))->shortcut().toString());
}

void MainWindow::on_setHotKey_clicked()
{
    auto index = ui->boxActions->currentIndex();

    if(index != 0)
    {
        actions[ui->boxActions->itemText(index)]->setShortcut(QKeySequence(ui->valHotKey->text()));
    }
}

void MainWindow::save()
{
    if(!file.isOpen() || file.fileName() != "")
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.length());
    }
}
