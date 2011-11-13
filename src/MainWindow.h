#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWebView>
#include "CommandLine.h"

class MainWindow : public QMainWindow {
	public:
		MainWindow();

	private:
		QWebView* view;
		CommandLine* command_line;
};

#endif
