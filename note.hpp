#ifndef NOTE_H
#define NOTE_H

#include <QLabel>
#include <QWidget>
#include <QPointer>
#include <QPushButton>

#include "json.hpp"

class Note final : public QWidget
{
	Q_OBJECT

	public:

		Note(const json& data);

	protected:

		virtual void enterEvent(QEvent* event) override;
		virtual void leaveEvent(QEvent* event) override;

	signals:

		void remove();

	protected:

		QPointer<QLabel> _title;
		QPointer<QLabel> _text;
		QPointer<QPushButton> _remove_btn;
};

#endif // NOTE_H
