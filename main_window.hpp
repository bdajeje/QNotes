#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QTabWidget>
#include <QPointer>

class MainWindow final : public QMainWindow
{
	Q_OBJECT

	public:

		MainWindow(QWidget *parent = 0);

	protected:

		void createPages();

	private slots:

		void closeTab(int index);
		void tabChanged(int index);

	protected:

		QPointer<QTabWidget> _tabs;
};

#endif // MAIN_WINDOW_HPP
