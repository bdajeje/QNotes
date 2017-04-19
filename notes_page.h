#ifndef NOTESPAGE_H
#define NOTESPAGE_H

#include <QWidget>
#include <QVBoxLayout>

#include "note.hpp"
#include "json.hpp"

class NotesPage final : public QWidget
{
	Q_OBJECT

	public:

		NotesPage();

		void addNote(const json& data);

	private slots:

		void removeNote();

	protected:

		QPointer<QVBoxLayout> _layout;
};

#endif // NOTESPAGE_H
