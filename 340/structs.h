#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct PersonData
{
	std::string surname{ "Иванов" };
	std::string name{ "Иван" };
	std::string middleName{ "Иванович" };
	std::string position{ "Бакалавр" };
	std::string country{ "Россия" };
	std::string region{ "Татарстан" };
	std::string city{ "Казань" };
	std::string street{ "Халитова" };
	std::string house{ "15" };
	std::string apartment{ "99" };
};

struct Person
{
	Person* next{};
	PersonData data{};
};

#endif