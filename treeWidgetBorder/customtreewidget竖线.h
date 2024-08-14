#ifndef CUSTOMTREEWIDGET_H
#define CUSTOMTREEWIDGET_H

#include <QTreeWidget>
#include <QPainter>
#include <QHeaderView>

class CustomTreeWidget : public QTreeWidget
{
public:
    explicit CustomTreeWidget(QWidget *parent = nullptr) : QTreeWidget(parent) {}

protected:
    void drawRow(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QTreeWidget::drawRow(painter, option, index);

        // Draw horizontal line at the bottom of the row
        QRect rect = option.rect;
        painter->save();
        painter->setPen(QPen(Qt::black, 1));
        painter->drawLine(rect.left(), rect.bottom(), rect.right(), rect.bottom());
        painter->restore();

        // Draw vertical lines between cells
        painter->save();
        painter->setPen(QPen(Qt::black, 1));

        int columnCount = this->columnCount();
        for (int column = 0; column < columnCount; ++column) {
            QModelIndex cellIndex = index.siblingAtColumn(column);
            QRect cellRect = visualRect(cellIndex);

            // Draw vertical line if not the last column
            if (column < columnCount - 1) {
                painter->drawLine(cellRect.right(), rect.top(), cellRect.right(), rect.bottom());
            }
        }

        painter->restore();
    }

private:
    QRect visualRect(const QModelIndex &index) const
    {
        // Calculate the visual rectangle of a cell
        QStyleOptionViewItem option = viewOptions();
        QRect rect = QTreeWidget::visualRect(index);
        return rect;
    }
};

#endif // CUSTOMTREEWIDGET_H
