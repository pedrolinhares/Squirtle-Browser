#include <QtGui>
#include "CommandLine.h"

CommandLine::CommandLine(QWidget* parent)
{
	setStyleSheet("border-style: none;"
				  "background-color: black;"
				  "font-family: \"Monospace\";"
				 );
	connect(this, SIGNAL(returnPressed()), this, SLOT(executeCommand()));
}

void CommandLine::executeCommand()
{
	QString command = text();
	QRegExp open(":open (.*)");
	if (open.exactMatch(command))
		emit(commandExecuted(open.cap(1)));
	emit(clear());
}
