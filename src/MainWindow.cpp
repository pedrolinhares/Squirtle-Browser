#include <QtGui>
#include "MainWindow.h"
#include "CommandLine.h"

MainWindow::MainWindow(){
	QUrl url("http://www.google.com");

	view = new QWebView(this);
	command_line = new CommandLine(this);

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(view);
	layout->addWidget(command_line);

	QWidget* centralWidget = new QWidget;
	centralWidget->setLayout(layout);

	setCentralWidget(centralWidget);

	view->load(url);

	resize(800, 600);
	showMaximized();
}
