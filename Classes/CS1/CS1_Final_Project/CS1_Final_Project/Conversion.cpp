#include "Conversion.h"

#include <iostream>
#include <cctype>

// Functional method of casting a string to char.
char Conversion::string_to_char(std::string str)
{
	return(str[0]);
}

// Converts string to integer. Returns int value. Returns -1 if value is negative or if value cannot be converted.
int Conversion::string_to_int(std::string str)
{
	int i;
	try
	{
		i = std::stoi(str);
		if(i < 0)
		{
			std::cout << "Error. Entered value must be positive." << std::endl;
			return(-1);
		}
		else
		{
			return(i);
		}
	}
	catch(std::invalid_argument)
	{
		std::cout << "Error. Entered value must be a number." << std::endl;
		return(-1);
	}
}

// Converts a string to all uppercase. 
void Conversion::to_uppercase(std::string *str)
{
	for(unsigned int i = 0; i < str->length(); i++)
	{
		str->at(i) = std::toupper(str->at(i));
	}
}
