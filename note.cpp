#include "note.hpp"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QEvent>

Note::Note(const json& data)
{
	auto main_layout = new QVBoxLayout;
	auto box = new QGroupBox(data.at("title").get<std::string>().c_str(), this);

	_text = new QLabel(data.at("text").get<std::string>().c_str());
	_remove_btn = new QPushButton("remove");
	_remove_btn->hide();

	main_layout->addWidget(_text);
	main_layout->addWidget(_remove_btn);
	box->setLayout(main_layout);
	main_layout->setAlignment(Qt::AlignCenter);

	connect(_remove_btn, SIGNAL(pressed()), this, SIGNAL(remove()));
}

void Note::enterEvent(QEvent* event)
{
	event->accept();
	_remove_btn->show();
}

void Note::leaveEvent(QEvent* event)
{
	event->accept();
	_remove_btn->hide();
}

