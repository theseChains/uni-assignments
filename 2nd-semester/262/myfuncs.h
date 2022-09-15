#ifndef MYFUNCS_H
#define MYFUNCS_H

#include "constants.h"
#include <fstream>

void ignoreLine();
int getNumber();
bool getAnswer();
int getRandomNumber();
std::string createRandomSequence(int n, std::ostream& out);
std::string createUserSequence(int n, std::ostream& out);
void abcAndAbaCount(std::string sequence, std::ostream& out);
void solve(std::ostream& out);
void fileSolve(std::ifstream& inf, std::ostream& out);
std::string getFileName(StreamType stream, std::string defaultFileName);

#endif