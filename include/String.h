#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:
	String();
	String(const char * s);
	String(const String & s);
	String(String && s);
	~String();

	String & operator=(const String & s);
	String & operator=(String && s);
	String operator+(const String & s);
	String & operator+=(const String & s);
	bool operator==(const String & s) const;
	bool operator!=(const String & s) const;

	String & append(const String & s);
	int compare(const String & s) const;
	size_t length() const;
	void resize(size_t n, char c = '\0');
	void clear();
	void swap(String & s);
	size_t substr(const String & s) const;
	String & insert(size_t pos, const String & s);
	String & insert(size_t pos, char c);

	friend std::ostream & operator<<(std::ostream & out, const String & str);
	friend std::istream & operator>>(std::istream & in, String & str);

private:
	size_t size;
	char * data;
};

#endif // STRING_H
