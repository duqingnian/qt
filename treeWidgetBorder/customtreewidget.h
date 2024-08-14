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
        // 调用基类的绘制方法，保持默认行为
        QTreeWidget::drawRow(painter, option, index);

        // 获取当前行的矩形区域
        QRect rect = option.rect;

        // 绘制完整的底部边框
        painter->save();
        painter->setPen(QPen(Qt::black, 1));
        painter->drawLine(rect.left(), rect.bottom(), rect.right(), rect.bottom());
        painter->restore();
    }
};

#endif
