#ifndef MY_FUNCS_H
#define MY_FUNCS_H

#include <fstream>

void ignoreLine();
int getNumber(char letter);
bool getAnswer();
int getRandomNumber(int min = 0, int max = 9);
int** initializeIntArray(int row, int col);
bool** initializeBoolArray(int row, int col);
void assignRandomValueAndPrintArray(int** initialArray, int row, int col, std::ostream& out);
void printArray(auto** array, int row, int col, std::ostream& out);
void deleteArray(auto**& array, int sizeOfArray);
void solve(std::ostream& out);
void fileSolve(std::ifstream& inf, std::ostream& out);

#endif