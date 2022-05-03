#ifndef MY_FUNCS_H
#define MY_FUNCS_H

#include <fstream>

void ignoreLine();
int getNumber();
double getValue(int k);
bool getAnswer();
void solution(std::ostream& out);
void printAnswer(double* numbers, int index, std::ostream& out);
void fileSolution(std::ifstream& inf, std::ostream& out);

#endif
