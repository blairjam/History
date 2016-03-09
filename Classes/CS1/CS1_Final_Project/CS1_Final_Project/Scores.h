#pragma once

class Scores
{
public:
	static const int QUESTIONS = 10; // Total number of questions.
	char key[QUESTIONS]; // Array that holds the answer key.

	double calculate_score(char[]);
	char calculate_grade(double);
private:
	static const int POINTS = 10; // The number of points each question is worth.
};
