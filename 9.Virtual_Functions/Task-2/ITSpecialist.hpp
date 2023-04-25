#ifndef IT_SPECIALIST_H
#define IT_SPECIALIST_H

#include <string>

#include "Employee.hpp"
#include "Project.hpp"

class ITSpecialist : public Employee {
private:
	Project** projects;
	unsigned int size;
	unsigned int capacity;

	void free() noexcept;

	void copy(const ITSpecialist& other);
	void move(ITSpecialist&& other) noexcept;

protected:
	ITSpecialist(std::string name, const unsigned int experience, const unsigned int salary);
	ITSpecialist(const ITSpecialist& other);
	ITSpecialist(ITSpecialist&& other) noexcept;

	double getAverageProjectsComplexity() const;

	ITSpecialist& operator=(const ITSpecialist& other);
	ITSpecialist& operator=(ITSpecialist&& other) noexcept;

	~ITSpecialist();

};

#endif // !IT_SPECIALIST_H

