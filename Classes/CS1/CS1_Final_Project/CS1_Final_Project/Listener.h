#pragma once

#include "Student.h"
#include "Conversion.h"

class Listener
{
public:
	void set_answer_key(char[], int); 
	bool obtain_info();
	void set_student_name(Student*);
	void set_student_id(Student*, Student[], int);
	void set_student_answers(Student*, int);
	bool run_again();
	int ask_sort();
	bool ask_search();
	int get_search_id();
private:
	Conversion conversion; // Conversion object for preforming unconventional conversions.
};
