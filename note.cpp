#include "note.hpp"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QEvent>

Note::Note(const json& data)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	auto main_layout = new QVBoxLayout(this);
//	auto box = new QGroupBox(data.at("title").get<std::string>().c_str(), this);

	_title = new QLabel(data.at("title").get<std::string>().c_str());
	_text = new QLabel(data.at("text").get<std::string>().c_str());
	_remove_btn = new QPushButton("remove");
//	_remove_btn->hide();

	main_layout->addWidget(_title);
	main_layout->addWidget(_text);
	main_layout->addWidget(_remove_btn);
//	box->setLayout(main_layout);
	main_layout->setAlignment(Qt::AlignLeft);

	connect(_remove_btn, SIGNAL(pressed()), this, SIGNAL(remove()));
}

void Note::enterEvent(QEvent* event)
{
	event->accept();
//	_remove_btn->show();R
}

void Note::leaveEvent(QEvent* event)
{
	event->accept();
//	_remove_btn->hide();
}

