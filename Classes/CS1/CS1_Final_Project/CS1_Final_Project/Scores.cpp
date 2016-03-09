#include "Scores.h"

// Calculates the score based on array of answers. Returns total score, total.
double Scores::calculate_score(char answers[])
{
	double total = 0;
	for(int i = 0; i < QUESTIONS; i++)
	{
		if(answers[i] == key[i])
		{
			total += POINTS;
		}
	}

	return(total);
}

// Calculates the letter grade based on total score, total. Returns letter grade, grade.
char Scores::calculate_grade(double total)
{
	char grade;
	
	if(total >= 90) grade = 'A';
	else if(total < 90 && total >= 80) grade = 'B';
	else if(total < 80 && total >= 70) grade = 'C';
	else if(total < 70 && total >= 60) grade = 'D';
	else grade = 'F';

	return(grade);
}
