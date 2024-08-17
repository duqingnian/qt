#include "testmessagebox.h"
#include "mymessagebox.h"

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
	m_titleBar->setTitleIcon(":/Resources/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("ǰ���е�С��-ǰ��֮·����ǰ��"));
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}


void TestMessageBox::onButtonClicked()
{
	// �������޸�showMyMessageBox()������������ʾ��ͬ����ʾ��;
	int result = MyMessageBox::showMyMessageBox(this, QStringLiteral("ɾ������"), QStringLiteral("��ȷ��Ҫɾ��XXX������"), MESSAGE_WARNNING, BUTTON_OK_AND_CANCEL, true);
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