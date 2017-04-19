#include "main_window.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	const QIcon icon{":images/icon.png"};
	app.setWindowIcon(icon);

	MainWindow window;
	window.show();

	return app.exec();
}
