#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QFileDialog>
#include <QKeyEvent>
#include <QShortcut>
#include <QMap>
#include "ref.h"

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

private:
    QTranslator translator;
    Ui::MainWindow *ui;
    QFile file;
    QMap<QString, QAction*> actions;
};

#endif // MAINWINDOW_H
