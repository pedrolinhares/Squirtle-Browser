#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWebView>
#include "CommandLine.h"

class QTabWidget;
class QAction;
class QString;
class QWebView;

class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow();

	private slots:
		void openNewTab();
		void openNewTab(QString);
		void adjustTitle(QString);
		void closeTab(int);
		void changeUrl(QString url);

	private:
		void createActions();
		QWebView* newView();

		QWebView* view;
		CommandLine* command_line;

		QTabWidget* tabWidget;
		QAction* newTabAction;
	
};

#endif
