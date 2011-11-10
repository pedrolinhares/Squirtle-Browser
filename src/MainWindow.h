#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWebView>

class MainWindow : public QMainWindow {
	public:
		MainWindow();

	private:
		QWebView* view;
};

#endif
