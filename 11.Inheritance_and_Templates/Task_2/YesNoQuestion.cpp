#include "YesNoQuestion.hpp"

YesNoQuestion::YesNoQuestion(const std::string& text, const double points, const std::string correctAnswer)
	: Question(text, points), correctAnswer(correctAnswer), givenAnswer("")
{
}

void YesNoQuestion::ask(std::ostream& output, std::istream& input) {
	Question::ask(output, input);
	output << "Please enter your answer: ";
	input >> givenAnswer;
}

double YesNoQuestion::grade() const {
	if (givenAnswer == correctAnswer) {
		return getPoints();
	}

	return 0.0;
}
