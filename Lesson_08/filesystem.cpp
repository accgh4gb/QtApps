#include "filesystem.h"

filesystem::filesystem(QWidget *parent) : QWidget(parent),
model(nullptr)
{
    model = new QFileSystemModel(this);
    model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);
    model->setRootPath("");
    path = new QLineEdit(this);

    gridLay = new QGridLayout(this);
    this->setLayout(gridLay);
    tree = new QTreeView(this);

    gridLay->addWidget(tree, 1, 0, 10, 10);
    gridLay->addWidget(path, 0, 0, 1, 10);
    setMinimumSize(200, 400);
    tree->setModel(model);

    tree->setColumnHidden(1, true);
    tree->setColumnHidden(2, true);
    tree->setColumnHidden(3, true);


    connect(tree, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_tree_doubleClicked(QModelIndex)));
    tree->setHeaderHidden(true);
}

QFileSystemModel *filesystem::getCurrentModel() const
{
    return model;
}

void filesystem::setNewModel(QFileSystemModel *newmodel)
{
    tree->setModel(newmodel);
    tree->setCurrentIndex(newmodel->index(curretnPath));
    path->setText(curretnPath);
    model = newmodel;
}

void filesystem::rebuildModel(QString path)
{
    curretnPath = path;
    QFileSystemModel *newModel = new QFileSystemModel(this);
    model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);
    model->setRootPath("");
    setNewModel(newModel);
}

void filesystem::chgDisk(int index)
{
    QFileInfoList list = QDir::drives();
    rebuildModel(list.at(index).path());
}

void filesystem::goMainPath()
{
    rebuildModel("/");
}

void filesystem::goToPath(QString path)
{
    rebuildModel(path);
}

void filesystem::on_tree_doubleClicked(const QModelIndex &index)
{
    QFileInfo file = model->fileInfo(index);
    QDir dir = file.dir();
    if (file.isDir())
    {
        path->setText(dir.absoluteFilePath(file.fileName()));
    }
    else if (file.isFile())
    {
        path->setText(dir.absoluteFilePath(file.fileName()));
    }
    tree->resizeColumnToContents(0);
}





