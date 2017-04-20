#include "notes_page.h"

#include <QScrollArea>

NotesPage::NotesPage()
{
	auto layout = new QVBoxLayout(this);

	auto scroll = new QScrollArea;
	auto content = new QWidget;
	_content_layout = new QVBoxLayout(content);

	content->setStyleSheet("background-color: blue;");


	layout->addWidget(scroll);
	scroll->setWidget(content);
	_content_layout->setSizeConstraint(QLayout::SetMinimumSize);
}

void NotesPage::addNote(const json& data)
{
	if(!_content_layout->isEmpty())
		addSeparator();

	auto note = new Note(data);
	_content_layout->addWidget(note);

	connect(note, SIGNAL(remove()), this, SLOT(removeNote()));
}

void NotesPage::removeNote()
{
	Note* note = static_cast<Note*>(QObject::sender());
	_content_layout->removeWidget(note);
	delete note;
}

void NotesPage::addSeparator()
{
	auto line = new QFrame;
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	_content_layout->addWidget(line);
}
