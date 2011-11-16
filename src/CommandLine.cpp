#include <QtGui>
#include "CommandLine.h"

CommandLine::CommandLine(QWidget* parent)
{
	setStyleSheet("border-style: none;"
				  "background-color: black;"
				  "font-family: \"Monospace\";"
				  "color: white;"
				 );
	connect(this, SIGNAL(returnPressed()), this, SLOT(executeCommand()));
}

void CommandLine::executeCommand()
{
	QString command = text();
	QRegExp open(":open (.*)");
	QRegExp rx("\\b(http://|https://)\\b");
	QRegExp newTab(":tabnew (.*)");

	int i = rx.indexIn(command);
	if (open.exactMatch(command) && i == -1)
		emit(openUrlRequested("http://" + open.cap(1)));
	
	if (open.exactMatch(command))
		emit(openUrlRequested(open.cap(1)));

	if (newTab.exactMatch(command))
		emit(newTabRequested(newTab.cap(1)));
	emit(clear());
}
