#include <array>
#include "constants.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "structs.h"
#include <vector>

void initializePersonData(std::stringstream& lineStream, Person*& p)
{
	std::string data{};
	std::array<std::string, constants::totalAttributes> dataList{};
	int index{ 0 };
	while (std::getline(lineStream, data, ','))
	{
		dataList[index] = data;
		++index;
	}

	p->data.surname = dataList[constants::surnameIndex];
	p->data.name = dataList[constants::nameIndex];
	p->data.middleName = dataList[constants::middleNameIndex];
	p->data.position = dataList[constants::positionIndex];
	p->data.country = dataList[constants::countryIndex];
	p->data.region = dataList[constants::regionIndex];
	p->data.city = dataList[constants::cityIndex];
	p->data.street = dataList[constants::streetIndex];
	p->data.house = dataList[constants::houseIndex];
	p->data.apartment = dataList[constants::apartmentIndex];
}

void getNextPerson(Person*& head, std::stringstream& lineStream)
{
	if (head == nullptr)
	{
		head = new Person{};
		initializePersonData(lineStream, head);
		head->next = head;
	}
	else
	{
		Person* indexPerson{ head };
		Person* newPerson{ new Person{} };
		while (indexPerson->next != head)
		{
			indexPerson = indexPerson->next;
		}
		initializePersonData(lineStream, newPerson);
		newPerson->next = head;
		indexPerson->next = newPerson;
	}
}

void getListFromFile(Person*& head, std::ifstream& inf)
{
	std::string line{};
	while (std::getline(inf, line))
	{
		std::stringstream lineStream{ line };
		getNextPerson(head, lineStream);
	}
	std::cout << "������ ��������.\n\n";
}

void printPerson(Person*& p, std::ostream& out)
{
	out << p->data.surname << ',' << p->data.name << ',' << p->data.middleName << ','
		<< p->data.position << ',' << p->data.country << ',' << p->data.region << ',' << p->data.city
		<< ',' << p->data.street << ',' << p->data.house << ',' << p->data.apartment << '\n';
}

void printList(Person*& head, std::ostream& out, Output output)
{
	std::cout << '\n';

	Person* temp{ head };
	int index{ 1 };

	if (head != nullptr)
	{
		while (true)
		{
			if (output == Output::console)
			{
				std::cout << index << ". ";
				++index;
			}
			printPerson(temp, out);
			temp = temp->next;
			if (temp == head)
				break;
		}
	}
	else
	{
		std::cout << "���� ����.\n";
		return;
	}

	std::cout << '\n';
}

void resetPerson(Person*& p)
{
	PersonData defaultPerson{};

	p->data.surname = defaultPerson.surname;
	p->data.name = defaultPerson.name;
	p->data.middleName = defaultPerson.middleName;
	p->data.position = defaultPerson.position;
	p->data.country = defaultPerson.country;
	p->data.region = defaultPerson.region;
	p->data.city = defaultPerson.city;
	p->data.street = defaultPerson.street;
	p->data.house = defaultPerson.house;
	p->data.apartment = defaultPerson.apartment;
}

void resetByIndex(Person*& head)
{
	Person* temp{ head };
	bool found{ false };
	int currIndex{ 1 };

	std::cout << "\n������� �����: ";
	int index{};
	std::cin >> index;
	std::cout << '\n';

	if (head != nullptr)
	{
		while (true)
		{
			if (currIndex == index)
			{
				resetPerson(temp);
				found = true;
				break;
			}
			++currIndex;
			temp = temp->next;
			if (temp == head)
				break;
		}
	}
	else
	{
		std::cout << "���� ����.\n";
		return;
	}

	if (!found)
		std::cout << "������� �� ������� ������ �� ������.\n\n";
}

void resetAll(Person*& head)
{
	Person* temp{ head };
	if (head != nullptr)
	{
		while (true)
		{
			resetPerson(temp);
			temp = temp->next;
			if (temp == head)
				break;
		}
	}
	else
	{
		std::cout << "���� ����.\n";
		return;
	}

	std::cout << '\n';
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getChoice(Choice ch)
{
	std::cout << (ch == Choice::sort ? "\n�����������" : "\n������") << " ��:\n";
	std::cout << "1 - �������\n2 - �����\n3 - ��������\n4 - ���������\n5 - ������\n";
	std::cout << "6 - �������\n7 - ������\n8 - �����\n9 - ����\n10 - ��������\n��������: ";

	while (true)
	{
		double choice{};
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "������� ����� �� 1 �� 10.\n";
		}
		else if (static_cast<int>(choice) != choice || choice < 1 || choice > 10)
		{
			ignoreLine();
			std::cout << "������� ����� ����� �� 1 �� 10.\n";
		}
		else
		{
			ignoreLine();
			return static_cast<int>(choice);
		}
	}
}

void swapData(const std::string& currDataStr, const std::string& indexDataStr, PersonData& currData, PersonData& indexData)
{
	if (currDataStr > indexDataStr)
	{
		PersonData temp{ currData };
		currData = indexData;
		indexData = temp;
	}
}

void sortChoice(Person*& current, Person*& index, int choice)
{                             
	switch (choice)   
	{
	case 1: swapData(current->data.surname, index->data.surname, current->data, index->data);		break;
	case 2: swapData(current->data.name, index->data.name, current->data, index->data);				break;
	case 3: swapData(current->data.middleName, index->data.middleName, current->data, index->data); break;
	case 4: swapData(current->data.position, index->data.position, current->data, index->data);		break;
	case 5: swapData(current->data.country, index->data.country, current->data, index->data);		break;
	case 6: swapData(current->data.region, index->data.region, current->data, index->data);			break;
	case 7: swapData(current->data.city, index->data.city, current->data, index->data);				break;
	case 8: swapData(current->data.street, index->data.street, current->data, index->data);			break;
	case 9: swapData(current->data.house, index->data.house, current->data, index->data);			break;
	case 10: swapData(current->data.apartment, index->data.apartment, current->data, index->data);	break;
	default: std::cout << "getChoice function fail";												break;
	}
}

void sortList(Person*& head)
{
	if (head == nullptr)
	{
		std::cout << "\n���� ����.\n";
		return;
	}

	int choice{ getChoice(Choice::sort) };
	Person* current{ head };
	Person* index{ nullptr };
	while (current->next != head)
	{
		index = current->next;
		while (index != head)
		{
			sortChoice(current, index, choice);
			index = index->next;
		}
		current = current->next;
	}
}

std::string getUserField(int choice)
{
	std::string field{};

	switch (choice)
	{
	case 1: std::cout << "������� �������: ";	std::getline(std::cin, field); 	break;
	case 2: std::cout << "������� ���: ";		std::getline(std::cin, field); 	break;
	case 3: std::cout << "������� ��������: ";	std::getline(std::cin, field); 	break;
	case 4: std::cout << "������� ���������: "; std::getline(std::cin, field); 	break;
	case 5: std::cout << "������� ������: ";	std::getline(std::cin, field); 	break;
	case 6: std::cout << "������� ������: ";	std::getline(std::cin, field); 	break;
	case 7: std::cout << "������� �����: ";		std::getline(std::cin, field); 	break;
	case 8: std::cout << "������� �����: ";		std::getline(std::cin, field); 	break;
	case 9: std::cout << "������� ���: ";		std::getline(std::cin, field); 	break;
	case 10: std::cout << "������� ��������: "; std::getline(std::cin, field); 	break;
	default: std::cout << "getChoice() function fail";							break;
	}

	return field;
}

std::string getPersonField(int choice, Person*& p)
{
	std::string personField{};

	switch (choice)
	{
	case 1:		personField = p->data.surname;				break;
	case 2:		personField = p->data.name;					break;
	case 3:		personField = p->data.middleName;			break;
	case 4:		personField = p->data.position;				break;
	case 5:		personField = p->data.country;				break;
	case 6:		personField = p->data.region;				break;
	case 7:		personField = p->data.city;					break;
	case 8:		personField = p->data.street;				break;
	case 9:		personField = p->data.house;				break;
	case 10:	personField = p->data.apartment;			break;
	default:	std::cout << "getChoice function fail";		break;
	}

	return personField;
}

Person*** getFoundListPtr(Person*& head, std::vector<Person**>& foundList)
{
	Person*** firstElementPtr{};

	int choice{ getChoice(Choice::find) };
	std::string userField{ getUserField(choice) };
	Person* temp{ head };
	if (head != nullptr)
	{
		while (true)
		{
			std::string personField{ getPersonField(choice, temp) };
			if (personField.contains(userField))
			{
				// allocate new memory so that we dont lose it once the function finishes
				Person** tempCopy{ new Person* { temp } };
				foundList.push_back(tempCopy);
			}
			temp = temp->next;
			if (temp == head)
				break;
		}
	}

	if (foundList.empty())
	{
		std::cout << "\n�������� �� ��������� ���� �� �������.\n\n";
		return nullptr;
	}
	else
	{
		firstElementPtr = &foundList.front();
		return firstElementPtr;
	}
}

void printFoundList(Person***& listPtr, std::vector<Person**>& foundList)
{
	if (!foundList.empty())
	{
		std::cout << "\n���� �������:\n";

		std::size_t listSize{ std::size(foundList) };
		for (std::size_t i{ 0 }; i < listSize; ++i)
		{
			printPerson(**listPtr, std::cout);
			++listPtr;
			delete foundList[i];
		}

		std::cout << '\n';
	}
}

void findAndPrint(Person*& head)
{
	std::vector<Person**> foundList{};
	Person*** listPtr{ getFoundListPtr(head, foundList) };
	printFoundList(listPtr, foundList);
}

void getListToFile(Person*& head)
{
	std::ofstream outf{ "list.txt" };

	if (!outf)
	{
		std::cerr << "�� ������� ������� ���� ��� ������.\n";
		return;
	}

	printList(head, outf, Output::file);
	std::cout << "������ �������� � ����.\n";
}

void cleanUp(Person*& head)
{
	Person* temp{ head };

	if (head != nullptr)
	{
		while (true)
		{
			Person* old{ temp };
			temp = temp->next;
			std::cout << "������� " << old->data.surname << ",... �����. ������ ���������� � ����.\n";
			delete old;
			if (temp == head)
				break;
		}
	}

	std::cout << "\n����� ���������.\n";
	std::system("chcp 866 > nul");
}

void programCycle()
{
	std::system("chcp 1251 > nul");

	std::ifstream inf{ "list.txt" };
	if (!inf)
	{
		std::cerr << "�� ������� ������� ���� ��� ������.\n";
		return;
	}

	Person* head{ nullptr };
	getListFromFile(head, inf);

	while (true)
	{
		std::cout << "1 - ������ ������\n2 - ������ � ���������� (�� ���������� ����)\n"
			<< "3 - ���������� ����������������� �������� �������� (�� ������)\n" 
			<< "4 - ���������� ����������������� �������� ���� ���������\n"
			<< "5 - ����� ���� ��������� (�� ���������� ����)\n6 - �����\n��������: ";
		int choice{};
		std::cin >> choice;

		switch (choice)
		{
		case 1: printList(head, std::cout, Output::console);						break;
		case 2: sortList(head); printList(head, std::cout, Output::console);		break;
		case 3: resetByIndex(head);													break;
		case 4: resetAll(head);														break;
		case 5: findAndPrint(head);													break;
		case 6: getListToFile(head); cleanUp(head);									return;
		default: std::cout << "�������� �����.\n������� ��� ���: ";					break;
		}
	}
}