#ifndef MYFUNCS_H
#define MYFUNCS_H

#include "constants.h"
#include "structs.h"
#include <vector>

void initializePersonData(std::stringstream& lineStream, Person*& p);
void printPerson(Person*& p, std::ostream& out);
void getNextPerson(Person*& head, std::stringstream& lineStream);
void getListFromFile(Person*& head, std::ifstream& inf);
void printList(Person*& head, std::ostream& out, Output output);
void resetPerson(Person*& p);
void resetByIndex(Person*& head);
void resetAll(Person*& head);
void swapData(const std::string& currDataStr, const std::string& indexDataStr, PersonData& currData, PersonData& indexData);
void sortChoice(Person*& current, Person*& index, int choice);
void ignoreLine();
int getChoice(Choice ch);
void sortList(Person*& head);
std::string getUserField(int choice);
Person*** getFoundListPtr(Person*& head, std::vector<Person**>& foundList);
void printFoundList(Person***& listPtr, std::vector<Person**>& foundList);
void findAndPrint(Person*& head);
void getListToFile(Person*& head);
void cleanUp(Person*& head);
void programCycle();

#endif