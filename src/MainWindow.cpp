#include <QtGui>
#include "MainWindow.h"

MainWindow::MainWindow(){
	QUrl url("http://www.google.com");

	view = new QWebView(this);

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(view);

	QWidget* centralWidget = new QWidget;
	centralWidget->setLayout(layout);

	setCentralWidget(centralWidget);

	view->load(url);

	resize(800, 600);
	showMaximized();
}
