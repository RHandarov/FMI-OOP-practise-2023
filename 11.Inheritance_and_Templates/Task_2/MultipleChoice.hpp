#ifndef MULTIPLE_CHOICE_H
#define MULTIPLE_CHOICE_H

#include <vector>
#include <string>

#include "Question.hpp"

class MultipleChoice : public Question {
private:
	std::vector<std::string> possibleAnswers;
	std::vector<int> correctAnswers;
	std::vector<int> givenAnswers;

	bool isAnswerCorrect(const unsigned int answerIndex) const;

public:
	MultipleChoice(const std::string& text, const double points,
		const std::vector<std::string>& possibleAnswers,
		const std::vector<int>& correctAnswers);

	void ask(std::ostream& output, std::istream& input) override;
	double grade() const override;
};

#endif // !MULTIPLE_CHOICE_H