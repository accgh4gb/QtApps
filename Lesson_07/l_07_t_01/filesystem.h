#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QWidget>
#include <QFileSystemModel>
#include <QDir>
#include <QTreeView>
#include <QGridLayout>
#include <QLineEdit>
#include <QScrollBar>

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class filesystem : public QWidget
{
    Q_OBJECT
public:
    explicit filesystem(QWidget *parent = nullptr);

    QFileSystemModel *getCurrentModel()const;
    void setNewModel(QFileSystemModel *newmodel);
    void rebuildModel(QString path);

private:
    QFileSystemModel *model;
    QGridLayout *gridLay;
    QTreeView *tree;
    QLineEdit *path;
    QString curretnPath;

private slots:
        void chgDisk(int index);
        void goMainPath();
        void goToPath(QString path);
        void on_tree_doubleClicked(const QModelIndex &index);
};

#endif // FILESYSTEM_H
