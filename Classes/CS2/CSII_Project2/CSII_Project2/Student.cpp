#include <iostream>

#include "Student.hpp"

Student::Student(std::string fname, std::string lname, int grades_)
	:first_name(fname), last_name(lname), num_grades(grades_), average(0)
{
	grades = new double[num_grades]; // Dynamically allocates a new array for the grades to be stored in.
}

Student::~Student()
{
}

// Accessor for the student's name.
std::string Student::get_name() const
{
	return(first_name + " " + last_name);
}

// Accessor for the number of grades the student has.
int Student::get_num_grades() const
{
	return(num_grades);
}

// Accessor for the average grade of the student.
double Student::get_average() const
{
	return(average);
}

// Calculates and returns the letter grade based on the student's average grade.
char Student::get_letter_grade() const
{
	if(average >= 90) return('A');
	else if(average >= 80) return('B');
	else if(average >= 70) return('C');
	else if(average >= 60) return('D');
	else return('F');
}

// Accessor for the student's grade at element 'i'.
double Student::get_grade(int i) const
{
	return(grades[i]);
}

// Mutator for the grade array at element 'grade_num' with the value of 'score'.
void Student::set_grade(int grade_num, double score)
{
	grades[grade_num] = score;
}
