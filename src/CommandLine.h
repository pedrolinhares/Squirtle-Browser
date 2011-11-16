#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <QLineEdit>

class CommandLine : public QLineEdit {
	Q_OBJECT
    public:
		CommandLine(QWidget* parent);

    public slots:
		void executeCommand();

	signals:
		void openUrlRequested(QString url);
		void newTabRequested(QString url);
};

#endif
