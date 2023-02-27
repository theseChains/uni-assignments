#ifndef SETTINGS_H
#define SETTINGS_H

#include <termios.h>
#include <unistd.h>

void setUpTerminal(termios* newt, termios* oldt);
void resetTerminal(termios* oldt);

#endif
