#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 使用自定义的 CustomTreeWidget 替换默认的 treeWidget
    customTreeWidget = new CustomTreeWidget(this);
    customTreeWidget->setColumnCount(2);
    QStringList headers;
    headers << tr("Name") << tr("Description");
    customTreeWidget->setHeaderLabels(headers);

    ui->verticalLayout->addWidget(customTreeWidget);
    setupTreeWidget();  // 初始化树形结构
}


void Dialog::setupTreeWidget()
{
    // 创建顶层项目
    QTreeWidgetItem *topItem = new QTreeWidgetItem(customTreeWidget);
    topItem->setText(0, "Root Item");
    topItem->setText(1, "This is the root");
    topItem->setIcon(0, QIcon("://resource/icons/root.png"));

    // 创建子项目
    QTreeWidgetItem *childItem1 = new QTreeWidgetItem(topItem);
    childItem1->setText(0, "Child 1");
    childItem1->setText(1, "This is child 1");
    childItem1->setIcon(0, QIcon("://resource/icons/c0.png"));

    QTreeWidgetItem *childItem2 = new QTreeWidgetItem(topItem);
    childItem2->setText(0, "Child 2");
    childItem2->setText(1, "This is child 2");
    childItem2->setIcon(0, QIcon("://resource/icons/c0.png"));

    // 创建孙项目
    QTreeWidgetItem *grandChildItem = new QTreeWidgetItem(childItem1);
    grandChildItem->setText(0, "Grandchild");
    grandChildItem->setText(1, "This is grandchild");
    grandChildItem->setIcon(0, QIcon("://resource/icons/c1.png"));

    QTreeWidgetItem *c2 = new QTreeWidgetItem(grandChildItem);
    c2->setText(0, "Grandchild");
    c2->setText(1, "This is c2 child");
    c2->setIcon(0, QIcon("://resource/icons/c2.png"));

    // 设置展开状态
    customTreeWidget->expandAll();
}

Dialog::~Dialog()
{
    delete ui;
}
