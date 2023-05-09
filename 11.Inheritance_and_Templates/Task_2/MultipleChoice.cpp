#include "MultipleChoice.hpp"

bool MultipleChoice::isAnswerCorrect(const unsigned int answerIndex) const {
	for (unsigned int index = 0; index < correctAnswers.size(); ++index) {
		if (correctAnswers[index] == answerIndex) {
			return true;
		}
	}

	return false;
}

MultipleChoice::MultipleChoice(const std::string& text, const double points, const std::vector<std::string>& possibleAnswers, const std::vector<int>& correctAnswers)
	: Question(text, points), possibleAnswers(possibleAnswers), correctAnswers(correctAnswers)
{
}

void MultipleChoice::ask(std::ostream& output, std::istream& input) {
	Question::ask(output, input);

	output << "Possible answers:\n";
	for (unsigned int index = 0; index < possibleAnswers.size(); ++index) {
		output << (index + 1) << ") " << possibleAnswers[index] << std::endl;
	}

	output << "Please enter the number of answers: ";

	unsigned int numAnswers;
	input >> numAnswers;

	output << "Please enter the answers as numbers: ";

	givenAnswers.clear();

	for (unsigned int index = 0; index < numAnswers; ++index) {
		unsigned int answerIndex;
		input >> answerIndex;

		givenAnswers.push_back(answerIndex - 1);
	}
}

double MultipleChoice::grade() const {
	double finalGrade = 0.0;

	for (unsigned int index = 0; index < givenAnswers.size(); ++index) {
		if (isAnswerCorrect(givenAnswers[index])) {
			finalGrade += getPoints();
		} else {
			finalGrade -= getPoints();
		}
	}

	return finalGrade;
}
