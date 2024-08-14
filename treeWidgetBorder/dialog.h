#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "customtreewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setupTreeWidget();
private:
    Ui::Dialog *ui;
    CustomTreeWidget *customTreeWidget;
};
#endif // DIALOG_H
