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
    connect(ui->action_2, &QAction::triggered, this, &MainWindow::setLightTheme);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::setDarkTheme);
    connect(ui->addFile, &QAction::triggered, this, &MainWindow::addFile);
    connect(ui->printText, &QAction::triggered, this, &MainWindow::printText);
    connect(ui->setFont, &QAction::triggered, this, &MainWindow::chooseFont);

    fillBox();
    fmqw = new filesystem(ui->gridLayoutWidget);

    pText = new QTextEdit(this);
    ui->mdiArea->addSubWindow(pText);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
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
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    QString path = QFileDialog::getSaveFileName();
    if (path.isEmpty()) return;
    file.setFileName(path);
    if (file.open(QIODevice::WriteOnly)){
        QFileInfo fileInfo = file.fileName();
        QString title = fileInfo.fileName();
        active->setWindowTitle(title);

        QString text = Text->toPlainText();
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
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    Text->setReadOnly(true);
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) return;
    file.setFileName(path);
    if (file.open(QIODevice::ReadOnly)){
        QFileInfo fileInfo = file.fileName();
        QString title = fileInfo.fileName();
        active->setWindowTitle(title);

        QByteArray ba = file.readAll();
        QString text(ba);
        Text->setText(text);
    }
}

void MainWindow::OpenFile()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    Text->setReadOnly(false);
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) return;

    file.setFileName(path);
    if (file.open(QIODevice::ReadWrite)){
        QFileInfo fileInfo = file.fileName();
        QString title = fileInfo.fileName();
        active->setWindowTitle(title);

        QByteArray ba = file.readAll();
        QString text(ba);
        Text->setText(text);
    }
}

void MainWindow::CreateFile()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    Text->setReadOnly(false);
    Text->clear();
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
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    if(!file.isOpen() || file.fileName() != "")
    {
        QString text = Text->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.length());
    }

}

void MainWindow::setDarkTheme()
{
    fmqw->setStyleSheet("background-color: grey; color: white");
    setStyleSheet("QTextEdit { background-color: grey; color: white}"
                  "QMainWindow{background-color: silver}"
                  "QAbstractItemView{background-color: grey; color: white}"
                  "QComboBox{background-color: grey; color: white}"
                  "QLineEdit{background-color: grey; color: white}"
                  "QPushButton{background-color: grey; color: white}"
                  "QMenuBar{background-color: grey; color: white}"
                  "QMenu::item{background-color: grey; color: white}"
                  "QMenu::item::selected{background-color: silver; color: black}"
                  "QMenuBar::item::selected{background-color: silver; color: black}");
}

void MainWindow::setLightTheme()
{
    fmqw->setStyleSheet("background-color: white; color: black");
    setStyleSheet("QTextEdit { background-color: white; color: black}"
                  "QMainWindow{background-color: light}"
                  "QAbstractItemView{background-color: light; color: black}"
                  "QComboBox{background-color: light; color: black}"
                  "QLineEdit{background-color: white; color: black}"
                  "QPushButton{background-color: light; color: black}"
                  "QMenuBar{background-color: light; color: black}"
                  "QMenu::item{background-color: light; color: black}"
                  "QMenu::item::selected{background-color: lightblue}"
                  "QMenuBar::item::selected{background-color: lightblue}");
}

void MainWindow::addFile()
{
    QTextEdit *newText = new QTextEdit(this);
    QMdiSubWindow *newWindow = new QMdiSubWindow;
    newWindow->setWidget(newText);
    newWindow->setAttribute(Qt::WA_DeleteOnClose);
    ui->mdiArea->addSubWindow(newWindow);
    newWindow->show();
}

void MainWindow::printText()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Печать");
    if(dlg.exec() != QDialog::Accepted) return;
    Text->print(&printer);

}

void MainWindow::copyFont()
{
    textFormat = pText->textCursor().charFormat();
}

void MainWindow::pasteFont()
{
    pText->textCursor().setCharFormat(textFormat);
}

void MainWindow::chooseFont()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    QFont font = Text->textCursor().charFormat().font();
    QFontDialog dlg(font, this);
    bool pressedOK = true;
    font = dlg.getFont(&pressedOK);
    if(pressedOK)
    {
        QTextCharFormat textFormat;
        textFormat.setFont(font);
        Text->textCursor().setCharFormat(textFormat);
    }
}

void MainWindow::on_alignLeft_triggered()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    Text->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_alignCenter_triggered()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    Text->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_alignRight_triggered()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    QWidget *widget = active->widget();
    QTextEdit *Text = (QTextEdit*)widget;

    Text->setAlignment(Qt::AlignRight);
}
