#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QFileDialog>
#include <QKeyEvent>
#include <QShortcut>
#include <QMap>
#include <QGridLayout>
#include <QMdiArea>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextCharFormat>
#include <QFontDialog>
#include <QDateTime>
#include "mythread.h"
#include "ref.h"
#include "filesystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void getMenu(QMap<QString, QAction*> *keyActions);

protected:
    void keyReleaseEvent(QKeyEvent* event) override;

private slots:

    void SaveFile();

    void OpenRef();

    void LangToRus();

    void LangToEng();

    void OpenFile();

    void OpenReadOnly();

    void CreateFile();

    void exit();

    void fillBox();

    void on_boxActions_activated(int index);

    void on_setHotKey_clicked();

    void save();

    void setDarkTheme();

    void setLightTheme();

    void addFile();

    void printText();

    void copyFont();

    void pasteFont();

    void chooseFont();

    void on_alignLeft_triggered();

    void on_alignCenter_triggered();

    void on_alignRight_triggered();

    void on_insertData_clicked();

    void on_insertTime_clicked();

    void on_searchButton_clicked();

    void returnSearchPath(QString result);

private:
    QTranslator translator;
    Ui::MainWindow *ui;
    QFile file;
    QMap<QString, QAction*> actions;
    filesystem *fmqw;
    QTextEdit *pText;
    QTextCharFormat textFormat;

    myThread* thread;
    QString path;
};

#endif // MAINWINDOW_H
