#include "closable_tabs.hpp"

#include <QEvent>
#include <QTabBar>
#include <QLabel>
#include <QMouseEvent>

namespace {
	constexpr int ICON_SIZE = 15;
}

ClosableTabs::ClosableTabs()
	: _close_icon (":images/close_tab.png")
{
	_close_icon = _close_icon.scaled(QSize(ICON_SIZE,ICON_SIZE));
}

int ClosableTabs::addTab(QWidget *page, const QString &label)
{
	const auto result = QTabWidget::addTab(page, label);

	// Add special close button
	QLabel* close = new QLabel("bouh");
	close->setPixmap(_close_icon);
	close->setGeometry(0,0,20,20);
	close->hide();
	//	close->setStyleSheet("max-height: 14px; max-width: 15px; margin-right: 50px;");
	tabBar()->setTabButton(tabBar()->count() - 1, QTabBar::RightSide, close);

	return result;
}

int ClosableTabs::addTab(QWidget *widget, const QIcon& icon, const QString &label)
{
	return QTabWidget::addTab(widget, icon, label);
}

void ClosableTabs::enterEvent(QEvent* event)
{
	auto tab = tabUnderMouse(event);

	if(tab)
		tab->show();
}

void ClosableTabs::leaveEvent(QEvent* event)
{
	auto tab = tabUnderMouse(event);

	if(tab)
		tab->hide();
}

QWidget* ClosableTabs::tabUnderMouse(QEvent* event)
{
	if(event->type() != QEvent::MouseMove)
		return nullptr;

	QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
	int tab_index = tabBar()->tabAt(mouse_event->pos());

	if(tab_index == -1)
		return nullptr;

	event->accept();
	return tabBar()->tabButton(tab_index, QTabBar::RightSide);
}
