#include "testmessagebox.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestMessageBox w;
	w.show();
	return a.exec();
}
