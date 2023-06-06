#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

class Airplane
{
private:
	std::string m_model{};
	int m_yearOfManufacture{};

	Airplane* m_next{};
	Airplane* m_prev{};

public:
	Airplane();
	Airplane(const std::string& model, int yearOfManufacture);
	~Airplane() = default;

	void setModel(const std::string& model);
	void setYearOfManufacture(int yearOfManufacture);
	void setNext(Airplane* const next);
	void setPrev(Airplane* const prev);

	const std::string& getModel() const;
	std::string& getModel();
	int getYearOfManufacture() const;
	Airplane* getNext() const;
	Airplane* getPrev() const;
};

#endif
