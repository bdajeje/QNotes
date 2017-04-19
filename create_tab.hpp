#ifndef CREATETAB_H
#define CREATETAB_H

#include <QWidget>
#include <QPointer>
#include <QLineEdit>

class CreateTab final : public QWidget
{
	Q_OBJECT

	public:

		CreateTab();

		void focus();

	protected:

		QPointer<QLineEdit> _edit_line;
};

#endif // CREATETAB_H
