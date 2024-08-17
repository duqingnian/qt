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
	m_titleBar->setTitleContent(QStringLiteral("ǰ���е�С��-ǰ��֮·����ǰ��"));
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
	m_titleBar->setWindowBorderWidth(2);
}

void TestMessageBox::paintEvent(QPaintEvent *event)
{
	// ���ƴ��ڰ�ɫ����ɫ;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRect(QRect(0, 0, this->width(), this->height()));
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(255, 255, 255)));

	// ���ƴ��ڻ�ɫ�߿�;
	QPen pen(QColor(204, 204, 204));
	painter.setPen(pen);
	painter.drawRect(0, 0, this->width() - 1, this->height() - 1);

	// ���ƴ����Ϸ�����;
	QPainterPath pathHead;
	pathHead.setFillRule(Qt::WindingFill);
	pathHead.addRect(QRect(0, 0, this->width(), 2));
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathHead, QBrush(QColor(15, 151, 255)));

	return QWidget::paintEvent(event);
}


void TestMessageBox::onButtonClicked()
{
	int result = MyMessageBox::showMyMessageBox(this, QStringLiteral("ɾ��"), QStringLiteral("��ȷ��Ҫɾ����������"), MESSAGE_WARNNING, BUTTON_OK_AND_CANCEL, true);
	if (result == ID_OK)
	{
		ui.label->setText(QStringLiteral("�����ȷ��"));
	}
	else if (result == ID_CANCEL)
	{
		ui.label->setText(QStringLiteral("�����ȡ��"));
	}
	else
	{
		ui.label->setText(QStringLiteral("��ģ̬����"));
	}
}