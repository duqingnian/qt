#include "testmessagebox.h"
#include <QtWidgets/QApplication>
#include "mymessagebox.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestMessageBox w;
	w.show();
	return a.exec();
}
