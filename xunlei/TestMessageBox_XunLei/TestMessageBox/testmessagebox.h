#ifndef TESTMESSAGEBOX_H
#define TESTMESSAGEBOX_H

#include <QtWidgets/QWidget>
#include "ui_testmessagebox.h"
#include "basewindow.h"

class TestMessageBox : public BaseWindow
{
	Q_OBJECT

public:
	TestMessageBox(QWidget *parent = 0);
	~TestMessageBox();

private:
	void initTitleBar();

	void paintEvent(QPaintEvent *event);

protected slots:
	void onButtonClicked();

private:
	Ui::TestMessageBoxClass ui;
};

#endif // TESTMESSAGEBOX_H
