#include "Airplane.h"

Airplane::Airplane()
	: m_model{ "Default Model" }
	, m_yearOfManufacture{ 1970 }
	, m_next{ nullptr }
	, m_prev{ nullptr }
{
}

Airplane::Airplane(const std::string& model, int yearOfManufacture)
	: m_model{ model }
	, m_yearOfManufacture{ yearOfManufacture }
	, m_next{ nullptr }
	, m_prev{ nullptr }
{
}

void Airplane::setModel(const std::string& model)
{
	m_model = model;
}

void Airplane::setYearOfManufacture(int yearOfManufacture)
{
	m_yearOfManufacture = yearOfManufacture;
}

void Airplane::setNext(Airplane* const next)
{
	m_next = next;
}

void Airplane::setPrev(Airplane* const prev)
{
	m_prev = prev;
}

const std::string& Airplane::getModel() const
{
	return m_model;
}

std::string& Airplane::getModel()
{
	return m_model;
}

int Airplane::getYearOfManufacture() const
{
	return m_yearOfManufacture;
}

Airplane* Airplane::getNext() const
{
	return m_next;
}

Airplane* Airplane::getPrev() const
{
	return m_prev;
}
