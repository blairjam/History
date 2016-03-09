#pragma once

#include <string>

#include "Student.hpp"

class Math_Student : public Student
{
public:
	Math_Student(std::string fname, std::string lname);
	~Math_Student();
	std::string get_course();
	void calculate_average();
	double get_final_exam();
private:
	const int QUIZ_GRADES; // The number of quiz grades.
	const double QUIZ_PERCENTAGE; // Percentage of the average grade the quiz contributes.
	const double TEST_ONE_PERCENTAGE; // Percentage of the average grade the first test contributes.
	const double TEST_TWO_PERCENTAGE; // Percentage of the average grade the first test contributes.
	const double FINAL_PERCENTAGE; // Percentage of the average grade the final exam contributes.

	double calculate_quiz();
};
