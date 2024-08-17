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
	m_titleBar->setTitleContent(QStringLiteral("前行中的小猪-前行之路还需前行"));
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}


void TestMessageBox::onButtonClicked()
{
	// 在这里修改showMyMessageBox()方法参数，显示不同的提示框;
	int result = MyMessageBox::showMyMessageBox(this, QStringLiteral("删除好友"), QStringLiteral("您确定要删除XXX好友吗？"), MESSAGE_WARNNING, BUTTON_OK_AND_CANCEL, true);
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