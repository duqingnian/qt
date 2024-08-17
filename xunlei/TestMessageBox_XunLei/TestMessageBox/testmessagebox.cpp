#include "testmessagebox.h"
#include "mymessagebox.h"
#include <QPainter>

TestMessageBox::TestMessageBox(QWidget *parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);
	initTitleBar();
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}

TestMessageBox::~TestMessageBox()
{

}

void TestMessageBox::initTitleBar()
{
	m_titleBar->move(1, 2);
	m_titleBar->setBackgroundColor(255, 255, 255);
	m_titleBar->setTitleIcon(":/Resources/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("前行中的小猪-前行之路还需前行"));
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
	m_titleBar->setWindowBorderWidth(2);
}

void TestMessageBox::paintEvent(QPaintEvent *event)
{
	// 绘制窗口白色背景色;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRect(QRect(0, 0, this->width(), this->height()));
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(255, 255, 255)));

	// 绘制窗口灰色边框;
	QPen pen(QColor(204, 204, 204));
	painter.setPen(pen);
	painter.drawRect(0, 0, this->width() - 1, this->height() - 1);

	// 绘制窗口上方蓝条;
	QPainterPath pathHead;
	pathHead.setFillRule(Qt::WindingFill);
	pathHead.addRect(QRect(0, 0, this->width(), 2));
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathHead, QBrush(QColor(15, 151, 255)));

	return QWidget::paintEvent(event);
}


void TestMessageBox::onButtonClicked()
{
	int result = MyMessageBox::showMyMessageBox(this, QStringLiteral("删除"), QStringLiteral("您确定要删除此任务吗？"), MESSAGE_WARNNING, BUTTON_OK_AND_CANCEL, true);
	if (result == ID_OK)
	{
		ui.label->setText(QStringLiteral("结果：确定"));
	}
	else if (result == ID_CANCEL)
	{
		ui.label->setText(QStringLiteral("结果：取消"));
	}
	else
	{
		ui.label->setText(QStringLiteral("非模态窗口"));
	}
}