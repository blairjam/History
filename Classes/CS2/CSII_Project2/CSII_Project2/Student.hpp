#pragma once

#include <string>

class Student
{
public:
	static const int ENGLISH_GRADES = 4; // The number of grades the students in English will have.
	static const int HISTORY_GRADES = 3; // The number of grades the students in History will have.
	static const int MATH_GRADES = 8; // The number of grades the students in Math will have.

	Student(std::string fname, std::string lname, int grades);
	virtual ~Student();
	virtual std::string get_course() = 0;
	virtual void calculate_average() = 0;
	virtual double get_final_exam() = 0;

	std::string get_name() const;
	int get_num_grades() const;
	double get_average() const;
	char get_letter_grade() const;
	double get_grade(int grade_num) const;
	void set_grade(int grade_num, double score);

protected:
	std::string first_name; // The first name of the student.
	std::string last_name; // The last name of the student.
	int num_grades; // The number of grades the student has.
	double *grades; // Pointer to the array of grades for the student.
	double average; // Average grade of the student.
};
