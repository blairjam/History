#pragma once

#include <string>

#include "Student.hpp"

class History_Student : public Student
{
public:
	History_Student(std::string fname, std::string lname);
	~History_Student();
	std::string get_course();
	void calculate_average();
	double get_final_exam();
private:
	const double PAPER_PERCENTAGE; // Percentage of the average grade the term paper contributes.
	const double MIDTERM_PERCENTAGE; // Percentage of the average grade the midterm contributes.
	const double FINAL_PERCENTAGE; // Percentage of the average grade the final exam contributes.
};
