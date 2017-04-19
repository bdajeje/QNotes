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
	auto main_layout = new QVBoxLayout(central_widget);
	_tabs = new QTabWidget;
	_tabs->setTabsClosable(true);

	createPages();

	_tabs->addTab(new CreateTab, QIcon(":images/new_tab.png"), "");

	main_layout->addWidget(_tabs);
	main_layout->setAlignment(Qt::AlignCenter);
	setCentralWidget(central_widget);

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
	if(index == _tabs->count() - 1)
		static_cast<CreateTab*>(_tabs->widget(index))->focus();
}
