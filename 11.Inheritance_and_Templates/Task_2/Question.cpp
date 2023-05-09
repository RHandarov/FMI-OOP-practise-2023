#include "Question.hpp"

Question::Question(const std::string& text, const double points) : text(text), points(points) {
}

double Question::getPoints() const {
	return points;
}

const std::string& Question::getText() const {
	return text;
}

void Question::ask(std::ostream& output, std::istream& input) {
	output << text << std::endl;
}
