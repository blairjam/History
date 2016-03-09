#pragma once

#include <string>

class Student
{
public:	
	char answers[10]; // Array to hold answers of the student.

	int get_uid();
	std::string get_first_name();
	std::string get_last_name();
	double get_score();
	char get_grade();
	char get_answer(int);

	void set_uid(int);
	void set_first_name(std::string);
	void set_last_name(std::string);
	void set_answer(int, char);
	void set_score(double);
	void set_grade(char);
private:
	int uid; // The ID of the student.
	std::string first_name; // The first name of the student.
	std::string last_name; // The last name of the student.
	double score; // The total score of the student.
	char grade; // The letter grade of the student.
};
