#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Student.hpp"

class File_Input
{
public:
	File_Input();
	~File_Input();
	bool extract_data(std::string &path);
	std::vector<Student*> get_student_list() const;
private:
	std::ifstream file; // File to read student information from.
	std::vector<Student*> student_list; // Temporary vector to hold Student pointers.

	void find_student_info();
	void exit_on_error();
};
