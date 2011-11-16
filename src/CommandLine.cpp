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
	QRegExp newTab(":tabnew (.*)");
	if (open.exactMatch(command))
		emit(openUrlRequested(open.cap(1)));

	if (newTab.exactMatch(command))
		emit(newTabRequested(newTab.cap(1)));
	emit(clear());
}
