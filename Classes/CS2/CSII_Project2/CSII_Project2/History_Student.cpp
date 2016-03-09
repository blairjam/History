#include "History_Student.hpp"

History_Student::History_Student(std::string fname, std::string lname)
	:PAPER_PERCENTAGE(.25), MIDTERM_PERCENTAGE(.35), FINAL_PERCENTAGE(.4), Student(fname, lname, Student::HISTORY_GRADES)
{
}

History_Student::~History_Student()
{
	delete [] grades; // Deletes the dynamically allocated array grades.
}

// Returns the course the student is in.
std::string History_Student::get_course()
{
	return("History");
}

// Calculates the average grade for the student based on the percentages given in the project specification.
void History_Student::calculate_average()
{
	double term_paper = grades[0];
	double midterm = grades[1];
	double final_exam = grades[2];

	average = (term_paper * PAPER_PERCENTAGE) + (midterm * MIDTERM_PERCENTAGE) + (final_exam * FINAL_PERCENTAGE);
}

// Returns the grade for the final exam.
double History_Student::get_final_exam()
{
	return(grades[num_grades - 1]);
}
