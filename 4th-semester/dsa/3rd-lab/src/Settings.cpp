#include "Settings.h"

void setUpTerminal(termios* newt, termios* oldt)
{
    tcgetattr(STDIN_FILENO, oldt);
    *newt = *oldt;
    newt->c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, newt);
}

void resetTerminal(termios* oldt)
{
    tcsetattr(0, TCSANOW, oldt);
}
