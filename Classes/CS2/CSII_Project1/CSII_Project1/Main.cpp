#include <iostream>

#include "String.hpp"

int main()
{
	String str1 = "This string has ", str2 = "been concatonated."; 
	std::cout << str1 + str2 << std::endl << std::endl; // Uses operator+ and operator<<

	String *str3 = new String("This string has been copied."), str4 = *str3; // Uses copy constructor and operator=
	std::cout << str4 << std::endl << std::endl;

	String str5 = "string with no capitals";
	std::cout << "Before subscript access: " << str5 << std::endl;
	str5[0] = 'S'; // Uses operator[]
	std::cout << "After subscipt access: " << str5 << std::endl << std::endl;

	String str6 = "12345", str7 = "123456";
	if(str6 < str7) std::cout << "String 6 has fewer characters than String 7." << std::endl << std::endl; // Uses operator<
	else std::cout << "String 6 has more characters than String 7." << std::endl << std::endl;

	String str8 = "123", str9 = "12";
	if(str8 > str9) std::cout << "String 8 has more characters than String 9." << std::endl << std::endl; // Uses operator>
	else std::cout << "String 8 has fewer characters than String 9." << std::endl << std::endl;

	String str10 = "12345", str11("12345");
	if(str10 == str11) std::cout << "String 10 has the same amount of characters as String 11" << std::endl << std::endl; // Uses operator==
	else std::cout << "String 10 and 11 have different amounts of characters." << std::endl << std::endl;

	String str12 = "Four";
	std::cout << "String 12 has " << str12.get_length() << " characters." << std::endl << std::endl; // Uses get_length()

	std::cout << "There has been a total of " << String::get_count() << " String objects created." << std::endl; // Uses static count variable

	return(0);
}
