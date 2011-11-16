#include <QtGui>
#include "MainWindow.h"
#include "CommandLine.h"

MainWindow::MainWindow(){
	tabWidget = new QTabWidget(this);
	tabWidget->setMovable(true);
	tabWidget->setTabsClosable(true);
	tabWidget->setDocumentMode(true);

	connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
	createActions();

	QUrl url("http://www.google.com");

	view = newView();
	command_line = new CommandLine(this);

	connect(command_line, SIGNAL(openUrlRequested(QString)), this, SLOT(changeUrl(QString)));
	connect(command_line, SIGNAL(newTabRequested(QString)), this, SLOT(openNewTab(QString)));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(tabWidget);
	layout->addWidget(command_line);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	QWidget* centralWidget = new QWidget;
	centralWidget->setLayout(layout);

	setCentralWidget(centralWidget);

	tabWidget->addTab(view, url.toString());
	view->load(url);

	resize(800, 600);
	showMaximized();
}

void MainWindow::changeUrl(QString url)
{
	QWebView* currentView = static_cast<QWebView*> (tabWidget->currentWidget());
	currentView->load(url);
}

void MainWindow::createActions() {
	//NewTab Action
	newTabAction = new QAction(tr("New Tab"), this);
	newTabAction->setShortcut(QKeySequence(tr("Ctrl+t")));
	newTabAction->setStatusTip(tr("Open new Tab"));

	connect(newTabAction, SIGNAL(triggered()), this, SLOT(openNewTab()));
}

QWebView* MainWindow::newView() {
	QWebView* newView = new QWebView;

	connect(newView, SIGNAL(titleChanged(QString)), this, SLOT(adjustTitle(QString)));
	
	//view actions
	newView->addAction(newTabAction);

	return newView;
}

void MainWindow::adjustTitle(QString title) {
	setWindowTitle(tr("Squirtle Browser - (%1)").arg(title));
	int currentTabIndex = tabWidget->currentIndex();
	tabWidget->setTabText(currentTabIndex, title);
}

void MainWindow::openNewTab() {
	QWebView* new_view = newView();
	QUrl url("http://www.google.com");
	new_view->load(url);

	int tabIndex = tabWidget->addTab(new_view, url.toString());
	tabWidget->setCurrentIndex(tabIndex);
	//tabWidget->setStyleSheet("width: 40px;");
}

void MainWindow::openNewTab(QString url) {
	QWebView* new_view = newView();
	new_view->load(url);

	int tabIndex = tabWidget->addTab(new_view, url);
	tabWidget->setCurrentIndex(tabIndex);
}

void MainWindow::closeTab(int index) {
	delete tabWidget->widget(index);
}
