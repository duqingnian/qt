#ifndef CUSTOMTREEWIDGET_H
#define CUSTOMTREEWIDGET_H

#include <QTreeView>
#include <QPainter>
#include <QTreeWidget>
#include <QHeaderView>

class CustomTreeWidget : public QTreeWidget
{
public:
    explicit CustomTreeWidget(QWidget *parent = nullptr) : QTreeWidget(parent) {}

protected:
    void drawRow(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QTreeWidget::drawRow(painter, option, index);
        QRect rect = option.rect;
        painter->save();
        painter->setPen(QPen(Qt::black, 1));
        painter->drawLine(rect.left(), rect.bottom(), rect.right(), rect.bottom());
        painter->restore();
    }
};
#endif
