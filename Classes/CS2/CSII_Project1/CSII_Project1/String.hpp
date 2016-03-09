#pragma once

#include <ostream>
#include <istream>

class String
{
public:
	String();
	String(const char *chars);
	String(const String &right);
	~String();
	int get_length() const;
	static int get_count();

	String& operator+(const String &right);
	String& operator=(const String &right);
	char& operator[](const int &num);
	bool operator<(const String &right);
	bool operator>(const String &right);
	bool operator==(const String &right);
	friend std::istream& operator>>(std::istream &stream, String &str);
	friend std::ostream& operator<<(std::ostream &stream, const String &str);
private:
	static int count;
	char *index;
	int length;	

	void expand();

	static void increase_count();
	static void decrease_count();
};

