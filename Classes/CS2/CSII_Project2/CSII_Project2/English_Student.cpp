#include "English_Student.hpp"

English_Student::English_Student(std::string fname, std::string lname)
	:ATTENDANCE_PERCENTAGE(.1), PROJECT_PERCENTAGE(.3), MIDTERM_PERCENTAGE(.3), FINAL_PERCENTAGE(.3), Student(fname, lname, Student::ENGLISH_GRADES)
{
}

English_Student::~English_Student()
{
	delete [] grades; // Deletes the dynamically allocated array grades.
}

// Returns the course the student is in.
std::string English_Student::get_course()
{
	return("English");
}

// Calculates the average grade for the student based on the percentages given in the project specification.
void English_Student::calculate_average()
{
	double attendance = grades[0];
	double project = grades[1];
	double midterm = grades[2];
	double final_exam = grades[3];

	average = (attendance * ATTENDANCE_PERCENTAGE) + (project * PROJECT_PERCENTAGE) + (midterm * MIDTERM_PERCENTAGE) + (final_exam * FINAL_PERCENTAGE);
}

// Returns the grade for the final exam.
double English_Student::get_final_exam()
{
	return(grades[num_grades - 1]);
}
