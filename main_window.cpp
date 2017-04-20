#include "main_window.hpp"

#include <set>

#include <QVBoxLayout>
#include <QMessageBox>

#include "notes_page.h"
#include "json.hpp"
#include "file.hpp"
#include "create_tab.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	auto central_widget = new QWidget;
	central_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//	central_widget->setStyleSheet("background-color:red;");

	auto main_layout = new QVBoxLayout(central_widget);
	_tabs = new ClosableTabs;
	_tabs->setMovable(true);
	_tabs->setTabPosition(QTabWidget::TabPosition::South);

	createPages();

	_tabs->addTab(new CreateTab, QIcon(":images/new_tab.png"), "");

	main_layout->addWidget(_tabs);
	main_layout->setAlignment(Qt::AlignCenter);
	setCentralWidget(central_widget);

	setMinimumSize(QSize(200, 150));

	connect(_tabs, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
	connect(_tabs, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
}

void MainWindow::createPages()
{
	const auto data = json::parse(files::read("notes.json"));
	std::map<std::string, NotesPage*> categories;

	for(const auto& notes_data : data["notes"])
	{
		const std::string& category = notes_data["category"];
		auto found = categories.find(category);
		NotesPage* notes_page = 0;

		if(found == categories.end())
		{
			notes_page = new NotesPage;
			categories.emplace(category, notes_page);
			_tabs->addTab(notes_page, category.c_str());
		}
		else
			notes_page = found->second;

		notes_page->addNote(notes_data["note"]);
	}
}

void MainWindow::closeTab(int index)
{
	const auto user_choice = QMessageBox::question(this, "Confirmation", "Removing this tab will also remove all related notes. Are you sure ?");
	if(user_choice == QMessageBox::Yes)
		delete _tabs->widget(index);
}

void MainWindow::tabChanged(int index)
{
	auto create_tab = dynamic_cast<CreateTab*>(_tabs->widget(index));

	if(create_tab)
		create_tab->focus();
}
