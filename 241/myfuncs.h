#ifndef MY_FUNCS_H
#define MY_FUNCS_H

#include <fstream>

void ignoreLine();
int getNumber();
double getDoubleValue();
bool getAnswer();
void solution(std::ostream& out);
void fileSolution(std::ifstream& inf, std::ostream& out);

#endif
