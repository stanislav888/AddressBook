#include "addressbookmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setOrganizationName( "Amon-Ra" ); // Using as settings folder in registry
	AddressBookMainWindow w;
	w.show();

	return a.exec();
}
