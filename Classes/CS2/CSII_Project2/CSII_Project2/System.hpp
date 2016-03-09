#pragma once

#include <vector>
#include <string>

#include "Student.hpp"
#include "File_Input.hpp"

class System
{
public:
	System();
	~System();
	void execute();
private:
	File_Input fi; // File_Input object for obtaining student information.
	std::vector<Student*> student_list; // Vector of Student pointers to hold all the students.
	std::string file_path; // String to hold the path of the file containing student information.

	void get_user_input();
	void print_report();
};
