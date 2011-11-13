#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <QLineEdit>

class CommandLine : public QLineEdit {
    public:
        typedef QLineEdit super;
		CommandLine(QWidget* parent);
};

#endif
