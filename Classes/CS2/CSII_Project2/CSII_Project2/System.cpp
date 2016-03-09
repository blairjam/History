#include <iostream>

#include "System.hpp"

System::System()
{
}

System::~System()
{
}

// Handles the execution of the entire program.
void System::execute()
{
	bool invalid_file; // Value to check if file is opened correctly.
	do // Gets user input and checks to make sure the file entered exists.
	{
		get_user_input();
		invalid_file = !fi.extract_data(file_path);
		std::cout << "\n";
	}
	while(invalid_file);

	student_list = fi.get_student_list(); // Assigns the vector of Student pointers to the data found in the file.

	for(std::vector<Student*>::iterator it = student_list.begin(); it !=student_list.end(); ++it) // Calculates the average of each student.
	{
		(*it)->calculate_average();
	}

	print_report();
}

// Asks user to give the name or path of the file where the student grades are stored.
void System::get_user_input()
{
	std::string path;
	std::cout << "Enter the name of the file containing the grades: ";
	std::getline(std::cin, path);

	file_path = path;
}

// Prints the grade report for all classes.
void System::print_report()
{
	std::string course;
	std::cout << "Student Grade Report" << "\n--------------------" << std::endl;
	for(int i = 0; i < 3; ++i)
	{
		if(i == 0) course = "English";
		if(i == 1) course = "History";
		if(i == 2) course = "Math";
		// Prints the header containing the labels for the values printed underneath.
		std::cout << "\n\n" << course << " Class\n" << "\nStudent\t\t\tFinal\tFinal\tLetter\nName\t\t\tExam\tAvg\tGrade\n----------------------------------------------" << std::endl;

		// Prints the values of each student which are in the class specified.
		for(std::vector<Student*>::iterator it = student_list.begin(); it !=student_list.end(); ++it)
		{
			if((*it)->get_course() == course)
				std::cout << (*it)->get_name() << "\t\t" << (*it)->get_final_exam() << "\t" << (*it)->get_average() << "\t" << (*it)->get_letter_grade() << std::endl;
		}
	}
	std::cout << "\n\n";
}
