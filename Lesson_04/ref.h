#ifndef REF_H
#define REF_H

#include <QDialog>

namespace Ui {
class ref;
}

class ref : public QDialog
{
    Q_OBJECT

public:
    explicit ref(QWidget *parent = nullptr);
    ~ref();

private:
    Ui::ref *ui;
};

#endif // REF_H
