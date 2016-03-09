#include "Listener.h"

#include <iostream>
#include <string>
#include <cctype>

// Populates given array with user entered answer key.
void Listener::set_answer_key(char key[], int length)
{
	std::cout << "Please enter the answer key below: " << std::endl;
	std::string value;

	for(int i = 0; i < length; i++)
	{
		std::cout << "Answer " << i + 1 << ": ";
		std::getline(std::cin, value);
		conversion.to_uppercase(&value);
		
		if(value.length() != 1)
		{
			std::cout << "The entered answer can only be one letter long." << std::endl;
			i--;
		}
		else
		{
			char ans = conversion.string_to_char(value);
			if(ans != 'A' && ans != 'B' && ans != 'C' && ans != 'D')
			{
				std::cout << "The entered answer must be either A, B, C, or D." << std::endl;
				i--;
			}
			else key[i] = ans;
			
		}

	}
	std::cout << std::endl;
}


// Asks user to continue with entering student information. Returns true if 'yes', false if 'no'.
bool Listener::obtain_info()
{
	std::string ans;
	
	std::cout << "Would you like to enter student information? (Y|N) ";
	std::getline(std::cin, ans);
	conversion.to_uppercase(&ans);

	if(ans == "Y" || ans == "YES") return(true);
	else if(ans == "N" || ans == "NO") return(false);
	else
	{
		std::cout << "\nInvalid input. Please choose either 'Yes' or 'No'." << std::endl;
		return(obtain_info());
	}
}

// Gets info from user about student's name.
void Listener::set_student_name(Student *student)
{
	std::string first_name, last_name;

	std::cout << "\tStudent's First Name: ";
	std::getline(std::cin, first_name);

	std::cout << "\tStudent's Last Name: ";
	std::getline(std::cin, last_name);

	student->set_first_name(first_name);
	student->set_last_name(last_name);
}

// Gets info from user about student's ID. Checks to see if the entered ID has already been claimed by another student.
void Listener::set_student_id(Student *student, Student students[], int students_entered)
{
	std::string uid;
	int uID;
	bool ask_id = true, taken;

	while(ask_id)
	{
		taken = false;
		std::cout << "\tStudent's ID: ";
		std::getline(std::cin, uid);
		uID = conversion.string_to_int(uid);
		if(uID != -1)
		{
			for(int i = 0; i < students_entered; i++)
			{
				if(uID == students[i].get_uid())
				{
					std::cout << "That ID has already been taken by '" << students[i].get_first_name() << " " << students[i].get_last_name() << "'. Please enter a different ID." << std::endl;
					taken = true;
					break;
				}
			}
			if(!taken)
			{
				student->set_uid(uID);
				ask_id = false;
			}
		}
	}
}

// Gets info from user about student's answers.
void Listener::set_student_answers(Student *student, int answers)
{
	std::string ans;
	for(int i = 0; i < answers; i++)
	{
		std::cout << "\tAnswer " << i + 1 << ": ";
		std::getline(std::cin, ans);
		conversion.to_uppercase(&ans);

		if(ans.length() != 1)
		{
			std::cout << "The entered answer can only be one letter long." << std::endl;
			i--;
		}
		else
		{
			char a = conversion.string_to_char(ans);

			if(a != 'A' && a != 'B' && a != 'C' && a != 'D')
			{
				std::cout << "The entered answer must be either A, B, C, or D." << std::endl;
				i--;
			}
			else student->set_answer(i, a);
		}
	}
}

// Determines whether or not to run the program again. Returns true if 'yes', false if 'no'.
bool Listener::run_again()
{
	std::string ans;

	std::cout << "Would you like to run the 'EXAM GRADING AND REPORTING SYSTEM' again? (Y|N) ";
	std::getline(std::cin, ans);
	conversion.to_uppercase(&ans);

	if(ans == "Y" || ans == "YES") return(true);
	else if(ans == "N" || ans == "NO")
	{
		std::cout << "\n\nExiting Program...\n" << std::endl;
		return(false);
	}
	else
	{
		std::cout << "\nInvalid input. Please choose either 'Yes' or 'No'." << std::endl;
		return(run_again());
	}
}

// Asks user how the would like to sort the displayed results. Returns 0 if sort_by_name should be used, 1 if sort_by_id should be used.
// Recursive if user is dumb and doesn't know what to input.
int Listener::ask_sort()
{
	std::string input;

	std::cout << "\nHow would you like to sort the results, by name or ID? ";
	std::getline(std::cin, input);
	conversion.to_uppercase(&input);

	if(input == "NAME") return(0);
	else if(input == "ID") return(1);
	else
	{
		std::cout <<"\nInvalid input. Please choose either 'Name' or 'ID'." << std::endl;
		return(ask_sort());
	}
}

// Asks the user if they want to search for a student. Returns true if 'yes', false if 'no'.
bool Listener::ask_search()
{
	std::string ans;

	std::cout << "\nWould you like to search for a student and display his or her grade? (Y|N) ";
	std::getline(std::cin, ans);
	conversion.to_uppercase(&ans);

	if(ans == "Y" || ans == "YES") return(true);
	else if(ans == "N" || ans == "NO") return(false);
	else
	{
		std::cout << "\nInvalid input. Please choose either 'Yes' or 'No'." << std::endl;
		return(ask_search());
	}
}

// Gets the user id that the user would like to search for.
int Listener::get_search_id()
{
	std::string input;
	bool get_id = true;
	
	int id;

	std::cout << "Please enter the ID of the student you would like search for: ";
	std::getline(std::cin, input);
	id = conversion.string_to_int(input);

	if(id != -1) return(id);
	else return(get_search_id());

}
