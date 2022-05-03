#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct PersonData
{
	std::string surname{ "������" };
	std::string name{ "����" };
	std::string middleName{ "��������" };
	std::string position{ "��������" };
	std::string country{ "������" };
	std::string region{ "���������" };
	std::string city{ "������" };
	std::string street{ "��������" };
	std::string house{ "15" };
	std::string apartment{ "99" };
};

struct Person
{
	Person* next{};
	PersonData data{};
};

#endif