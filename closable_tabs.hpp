#ifndef CLOSABLETABS_H
#define CLOSABLETABS_H

#include <QTabWidget>
#include <QPixmap>

class ClosableTabs final : public QTabWidget
{
	Q_OBJECT

	public:

		ClosableTabs();

		int addTab(QWidget *page, const QString &label);
		int addTab(QWidget *widget, const QIcon& icon, const QString &label);

	protected:

		virtual void enterEvent(QEvent* event) override;
		virtual void leaveEvent(QEvent* event) override;
		QWidget* tabUnderMouse(QEvent* event);

	protected:

		QPixmap _close_icon;
};

#endif // CLOSABLETABS_H
