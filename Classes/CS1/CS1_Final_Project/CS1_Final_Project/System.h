#pragma once

#include "Listener.h"
#include "Scores.h"
#include "Student.h"

#include <string>

class System
{
public:
	System();
	void execute();
	static const int STUDENTS = 10; // The maximum number of students.
private:
	Listener listener; // Listener object for user input.
	Scores scores; // Scores object for score handling.
	Student student[STUDENTS]; // Array of Student objects.
	bool running; // Value for the program to test for in its main loop.
	int students_entered; // The number of students the user enters into the system.
	bool sorted_by_id; // Value to hold what sorting method the user used. 

	void get_student_info();
	void calculate_grades();
	void print_report(int, int, std::string);
	void print_report(int);
	void sort();
	void sort_by_name();
	void sort_by_id();
	void search();
};
