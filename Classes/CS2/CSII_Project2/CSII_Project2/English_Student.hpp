#pragma once

#include <string>

#include "Student.hpp"

class English_Student : public Student
{
public:
	English_Student(std::string fname, std::string lname);
	~English_Student();
	std::string get_course();
	void calculate_average();
	double get_final_exam();
private:
	const double ATTENDANCE_PERCENTAGE; // Percentage of the average grade the attendance contributes.
	const double PROJECT_PERCENTAGE; // Percentage of the average grade the project contributes.
	const double MIDTERM_PERCENTAGE; // Percentage of the average grade the midterm contributes.
	const double FINAL_PERCENTAGE; // Percentage of the average grade the final exam contributes.
};
