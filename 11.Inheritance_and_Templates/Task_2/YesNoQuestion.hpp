#ifndef YES_NO_QUESTION_H
#define YES_NO_QUESTION_H

#include <string>

#include "Question.hpp"

class YesNoQuestion : public Question {
private:
	std::string correctAnswer;
	std::string givenAnswer;

public:
	YesNoQuestion(const std::string& text, const double points, const std::string correctAnswer);

	void ask(std::ostream& output, std::istream& input) override;
	double grade() const override;
};

#endif // !YES_NO_QUESTION_H