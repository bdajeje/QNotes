#include "create_tab.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

CreateTab::CreateTab()
{
	auto layout = new QVBoxLayout(this);
	auto label = new QLabel("Enter a name for the new category");
	_edit_line = new QLineEdit;
	auto accept_btn = new QPushButton("Create");

	layout->setAlignment(Qt::AlignCenter);

	layout->addWidget(label);
	layout->addWidget(_edit_line);
	layout->addWidget(accept_btn);
}

void CreateTab::focus()
{
	_edit_line->setFocus();
}
