#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QPointer>

#include "closable_tabs.hpp"

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

		QPointer<ClosableTabs> _tabs;
};

#endif // MAIN_WINDOW_HPP
