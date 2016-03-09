#include <iostream>

#include "Math_Student.hpp"

Math_Student::Math_Student(std::string fname, std::string lname)
	:QUIZ_GRADES(5), QUIZ_PERCENTAGE(.15), TEST_ONE_PERCENTAGE(.25), TEST_TWO_PERCENTAGE(.25), FINAL_PERCENTAGE(.35), Student(fname, lname, Student::MATH_GRADES)
{
}

Math_Student::~Math_Student()
{
	delete [] grades; // Deletes the dynamically allocated array grades.
}

// Returns the course the student is in.
std::string Math_Student::get_course()
{
	return("Math");
}

// Calculates the average grade for the student based on the percentages given in the project specification.
void Math_Student::calculate_average()
{
	double quiz = calculate_quiz();
	double test_one = grades[5];
	double test_two = grades[6];
	double final_exam = grades[7];

	average = (quiz * QUIZ_PERCENTAGE) + (test_one * TEST_ONE_PERCENTAGE) + (test_two * TEST_TWO_PERCENTAGE) + (final_exam * FINAL_PERCENTAGE);
}

// Returns the grade for the final exam.
double Math_Student::get_final_exam()
{
	return(grades[num_grades - 1]);
}


// Calculates the average quiz grade.
double Math_Student::calculate_quiz()
{
	double total = 0;

	for(int i = 0; i < QUIZ_GRADES; ++i)
	{
		total += grades[i];
	}

	return(total / QUIZ_GRADES);
}
