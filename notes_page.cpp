#include "notes_page.h"

NotesPage::NotesPage()
{
	_layout = new QVBoxLayout(this);
}

void NotesPage::addNote(const json& data)
{
	auto note = new Note(data);
	_layout->addWidget(note);

	connect(note, SIGNAL(remove()), this, SLOT(removeNote()));
}

void NotesPage::removeNote()
{
	Note* note = static_cast<Note*>(QObject::sender());
	_layout->removeWidget(note);
	delete note;
}
