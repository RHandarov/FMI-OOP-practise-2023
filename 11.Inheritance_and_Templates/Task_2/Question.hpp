#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>

class Question {
private:
	std::string text;
	double points;

protected:
	Question(const std::string& text, const double points);

	double getPoints() const;
	const std::string& getText() const;

public:
	virtual void ask(std::ostream& output, std::istream& input);
	virtual double grade() const = 0;
};

#endif // !QUESTION_H
