#include "Student.h"

// Returns uid of the student.
int Student::get_uid()
{
	return(uid);
}

// Returns first name of the student.
std::string Student::get_first_name()
{
	return(first_name);
}

// Returns last name of the student.
std::string Student::get_last_name()
{
	return(last_name);
}

// Returns score of the student.
double Student::get_score()
{
	return(score);
}

// Returns letter grade of the student.
char Student::get_grade()
{
	return(grade);
}

// Returns the answer at question q.
char Student::get_answer(int q)
{
	return(answers[q]);
}

// Sets the student's uid.
void Student::set_uid(int id)
{
	uid = id;
}

// Sets the student's first name.
void Student::set_first_name(std::string nm)
{
	first_name = nm;
}

// Sets the student's last name.
void Student::set_last_name(std::string nm)
{
	last_name = nm;
}

// Sets the student's answer a, for question q.
void Student::set_answer(int q, char a)
{
	answers[q] = a;
}

// Sets the student's score.
void Student::set_score(double scr)
{
	score = scr;
}

// Sets the student's letter grade.
void Student::set_grade(char grd)
{
	grade = grd;
}
