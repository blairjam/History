#include "System.h"

#include <iostream>

System::System()
{
	running = true;
}

// 'Main' function. Makes calls to the rest of the program for execution.
void System::execute()
{
	std::cout << "----------EXAM GRADING AND REPORTING SYSTEM----------\n" << std::endl;
	while(running)
	{
		listener.set_answer_key(scores.key, scores.QUESTIONS);
		get_student_info();

		if(students_entered != 0)
		{
			calculate_grades();
			sort();
			print_report(100, 0, "Grading Report:");
			print_report(100, 80, "Students Admitted to the Graduate Program:");
			print_report(79, 70, "Students with Conditional Admittance to the Graduate Program:");
			print_report(69, 0, "Students not Admitted to the Graduate Program:");
			search();
		}

		running = listener.run_again();
	}
}

// Gets input from user concerning student name, id, and answers. 
void System::get_student_info()
{
	students_entered = 0;
	for(int i = 0; i < STUDENTS	&& listener.obtain_info(); i++)
	{
		std::cout << "\nEntering student " << i + 1 << " information: " << std::endl;
		listener.set_student_name(&student[i]);
		listener.set_student_id(&student[i], student, students_entered);
		listener.set_student_answers(&student[i], scores.QUESTIONS);
		students_entered++;
	}
}

// Makes calls to Scores class to calculate student grades.
void System::calculate_grades()
{
	for(int i = 0; i < students_entered; i++)
	{
		double score = scores.calculate_score(student[i].answers);
		char grade = scores.calculate_grade(score);

		student[i].set_score(score);
		student[i].set_grade(grade);
	}
}

// Displays the report table for the report type, report, where the students scores fall between high_score and low_score.
void System::print_report(int high_score, int low_score, std::string report)
{
	std::cout << std::endl << std::endl << report << std::endl;
	std::cout << "\nStudent ID" << "\tStudent Name" << "\tAnswers" << "\t\tScore" << "\tGrade" << std::endl;
	std::cout << "__________" << "\t____________" << "\t__________" << "\t_____" << "\t_____" << std::endl;

	for(int i = 0; i < students_entered; i++)
	{
		if(student[i].get_score() <= high_score && student[i].get_score() >= low_score)
		{
			std::cout << student[i].get_uid();
			std::cout << "\t\t" << student[i].get_last_name() << "," << student[i].get_first_name() << "\t";

			for(int q = 0; q < scores.QUESTIONS; q++)
			{
				std::cout << student[i].get_answer(q);
			}

			std::cout << "\t" << student[i].get_score();
			std::cout << "\t" << student[i].get_grade() << std::endl;
		}

	}
}

// Displays the report table for the student at posistion, pos, in the student array.
void System::print_report(int pos)
{
	std::cout << "\nStudent ID" << "\tStudent Name" << "\tAnswers" << "\t\tScore" << "\tGrade" << std::endl;
	std::cout << "__________" << "\t____________" << "\t__________" << "\t_____" << "\t_____" << std::endl;
	std::cout << student[pos].get_uid();
	std::cout << "\t\t" << student[pos].get_last_name() << "," << student[pos].get_first_name() << "\t";

	for(int q = 0; q < scores.QUESTIONS; q++)
	{
		std::cout << student[pos].get_answer(q);
	}

	std::cout << "\t" << student[pos].get_score();
	std::cout << "\t" << student[pos].get_grade() << std::endl;
}

// Decides to sort by name or id.
void System::sort()
{
	if(listener.ask_sort() == 0)
	{
		sort_by_name();
	}
	else
	{
		sort_by_id();
	}
}

// Sorts student array by name. 
// Swaps students if name letter l is greater than letter l of the next student. 
// Skips the swap if the letter l is less than the the letter l of the next student.
// Proceeds with the letter loop is the letters, l, are equal.
void System::sort_by_name()
{
	sorted_by_id = false;
	bool swap;
	Student temp_student;

	do
	{
		swap = false;
		for(int i = 0; i < students_entered - 1; i++)
		{
			for(unsigned int l = 0; l < student[i].get_last_name().length(); l++)
			{
				if(student[i].get_last_name()[l] > student[i + 1].get_last_name()[l])
				{
					temp_student = student[i];
					student[i] = student[i + 1];
					student[i + 1] = temp_student;
					swap = true;
					break;
				}
				else if(student[i].get_last_name()[l] < student[i + 1].get_last_name()[l])
				{
					break;
				}
			}
		}
	}
	while(swap);
}

// Sorts the student array by ID.
// Preforms a swap if student's ID is greater than the next student's ID.
void System::sort_by_id()
{
	sorted_by_id = true;
	bool swap;
	Student temp_student;

	do
	{
		swap = false;
		for(int i = 0; i < students_entered - 1; i++)
		{
			if(student[i].get_uid() > student[i + 1].get_uid())
			{
				temp_student = student[i];
				student[i] = student[i + 1];
				student[i + 1] = temp_student;
				swap = true;
			}
		}
	}
	while(swap);
}

// Searches the array of students for the student with the id of value. Uses a binary search algorithm to effectively search for the student.
void System::search()
{
	while(listener.ask_search())
	{
		int first = 0, middle, last = students_entered - 1, position = -1, value;
		bool found = false;

		if(!sorted_by_id) sort_by_id();

		value = listener.get_search_id();

		while(!found && first <= last)
		{
			middle = (first + last) / 2;
			if(student[middle].get_uid() == value)
			{
				found = true;
				position = middle;
			}
			else if(student[middle].get_uid() > value)
			{
				last = middle - 1;
			}
			else
			{
				first = middle + 1;
			}
		}
		if(position == -1)
		{
			std::cout << "The student with an ID of '" << value << "' could not be found." << std::endl; 
		}
		else
		{
			print_report(position);
		}
	}	
}
