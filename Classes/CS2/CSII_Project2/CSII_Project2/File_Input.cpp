#include <iostream>

#include "File_Input.hpp"
#include "Math_Student.hpp"
#include "English_Student.hpp"
#include "History_Student.hpp"

File_Input::File_Input()
{
}

File_Input::~File_Input()
{
}

// Opens and closes file. Returns false if the file doesn't exist.
bool File_Input::extract_data(std::string &path)
{
	file.open(path);

	if(!file) // Checks if the file was opened correctly.
	{
		std::cerr << "The file at '" << path << "' could not be opened. Please check the existance of the file and try again." << std::endl;
		return(false);
	}

	find_student_info(); // Get info from file.

	file.close();
	return(true);
}

// Gets the student's information from the file. Dynamically allocates new Student types to hold the respective students. Pushes Student type into temporary vector student_list.
void File_Input::find_student_info()
{
	Student *student; // Student pointer to be allocated to a Student type and temporarily hold information.

	std::string fname; // String to hold the first name of the student.
	std::string lname; // String to hold the last name of the student.
	std::string course; // String to hold the course name of the student.

	double score; // Double to hold the next score of the student.

	while(!file.eof()) // Runs until the end of the file is reached.
	{
		std::getline(file, lname, ','); // Gets the line up to the comma.
		file >> fname; // Gets the rest of the available line.
		file >> course; // Gets the course name from the next line.

		if(course == "English") student = new English_Student(fname, lname); // Allocates student to an english student if the course found was english.
		else if(course == "History") student = new History_Student(fname, lname); // Allocates student to a history student if the course found was history.
		else if(course == "Math") student = new Math_Student(fname, lname); // Allocates student to a math student if the course found was math.
		else
		{
			student = NULL;
			exit_on_error(); // Runs if the course doesn't match any of the available courses.
		}

		for(int i = 0; i < student->get_num_grades(); ++i) // Gets the grades in order for the student.
		{
			if(file >> score) student->set_grade(i, score); // Checks if the next input can be stored as a double. Then sets the grade at element 'i' to a value of 'score'.
			else exit_on_error(); // Exits because the next piece of data can't be stored as a double.
		}

		file.ignore(); // Ingores the next character in the file.

		student_list.push_back(student); // Inserts the student into the vector of Student pointers.
	}
}

// Returns the vector of Student pointers.
std::vector<Student*> File_Input::get_student_list() const
{
	return(student_list);
}

// Exits the program if the file is not formatted correctly.
void File_Input::exit_on_error()
{
	std::cerr << "\aThe file given is not formatted correctly. Please check the file and run the program again." << std::endl;
	std::exit(1);
}
