#include <iostream>

#include "String.hpp"

int String::count = 0; // Assigns initial object count to 0.

String::String()
	:length(0) // Assigning initial length.
{
	increase_count(); // Increases total object count.
}

String::String(const char *chars)
	:length(0) // Assigning initial length.
{
	while(chars[length] != NULL) // Increasing the length of our char array based on the amount of chars given.
	{
		length++;
	}

	index = new char[length]; // Creating a new char array based on the length found.

	for(int i = 0; i < length; ++i) // Assigning each char in the index to the corresponding char given.
	{
		index[i] = chars[i];
	}

	increase_count(); // Increases total object count.
}

String::String(const String &right)
{
	length = right.length; // Assign length to that of object on right side.

	index = new char[length]; // Creating a new char array based on the length found.

	for(int i = 0; i < length; ++i) // Assigning each char in the index to the corresponding char from the right side.
	{
		index[i] = right.index[i];
	}

	increase_count(); // Increases total object count.
}

// Destructor. Frees memory after object is deleted.
String::~String()
{
	delete [] index;
	decrease_count(); // Decreases total object count.
}

// Returns length of string.
int String::get_length() const
{
	return(length);
}

// Increases object count.
void String::increase_count()
{
	++count;
}

// Decreases object count.
void String::decrease_count()
{
	--count;
}

// Returns current object count.
int String::get_count()
{
	return(count);
}

// Expands the current index by one. Currently crashes program. Not sure how to fix. Used with operator>>.
void String::expand()
{
	char *temp = index;
	index = new char[length + 1];

	for(int i = 0; i < length; ++i)
	{
		index[i] = temp[i];
	}

	length += 1;

	delete [] temp; // Problems here........
}

// Overloaded + operator. Concatonates strings.
String& String::operator+(const String &right)
{
	char *temp = index; // Create temporary storage for the current index.
	int new_length = length + right.length; // Find the total length of the new string.

	index = new char[new_length]; // Point the index to a new array.

	for(int i = 0; i < length; ++i) // Set the first part of the index to the temp index.
	{
		index[i] = temp[i];
	}

	for(int i = length, j = 0; i < new_length; ++i, ++j) // Set the second part of the index to the right index.
	{
		index[i] = right.index[j];
	}

	length = new_length; // Assign the length to be the new length.
	delete [] temp; // Delete the temporary storage.
	
	return(*this);
}

// Overload of = operator. Sets *this equal to string on right.
String& String::operator=(const String &right)
{
	length = right.length; // Assign length to that of object on right side.

	index = new char[length]; // Creating a new char array based on the length found.

	for(int i = 0; i < length; ++i) // Assigning each char in the index to the corresponding char from the right side.
	{
		index[i] = right.index[i];
	}

	return(*this);
}

// Overload of [] operator. Returns the char at index[num] if num doesn't fall out of bounds.
char& String::operator[](const int &subscript)
{
	if(subscript < 0 || subscript > length - 1) // Bound testing.
	{	
		std::cerr << "\aERROR: Index is out of bounds at subscript: " << subscript << std::endl;
		std::exit(1); // Exit with error status 1.
	}

	return(index[subscript]);
}

// Overload of < operator. Returns true if calling object has fewer characters than given object.
bool String::operator<(const String &right)
{
	if(length < right.length) return(true);
	else return(false);
}

// Overload of > operator. Returns true if calling object has more characters than given object.
bool String::operator>(const String &right)
{
	if(length > right.length) return(true);
	else return(false);
}

// Overload of == operator. Returns true if calling object and given object have the same amount of characters.
bool String::operator==(const String &right)
{
	if(length == right.length) return(true);
	else return(false);
}



// Overload of >> operator. Currently has problems with expanding index array.
std::istream& operator>>(std::istream &stream, String &str)
{
	str.length = 0;

	while(stream.good()) 
	{
		if(stream.peek() == ' ') break;
		str.expand();
		stream >> str.index[str.length];
	}

	return(stream);
}

// Overload of << operator. Writes *index to stream.
std::ostream& operator<<(std::ostream &stream, const String &str)
{
	for(int i = 0; i < str.length; ++i) // Writes each character of index to stream.
	{
		stream << str.index[i];
	}
	return(stream);
}