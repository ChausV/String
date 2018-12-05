#include "String.h"
#include <cstring>
#include <cctype>
#include <utility>
#include <stdexcept>

String::String() : size(0), data(nullptr)
{}

String::String(const char * s) : size(strlen(s)), data(new char[size])
{
	strncpy(data, s, size);
}

String::String(const String & s) : size(s.size), data(new char[size])
{
	strncpy(data, s.data, size);
}

String::String(String && s) : size(std::exchange(s.size, 0)),
								data(std::exchange(s.data, nullptr))
{
	std::cout << "Move constructor" << std::endl;
}

String::~String()
{
	delete [] data;
	// std::cout << "Destructor" << std::endl;
}

String & String::operator=(const String & s)
{
	if (this == &s)
		return *this;
	size = s.size;
	delete [] data;
	data = new char[size];
	strncpy(data, s.data, size);

	return *this;
}

String & String::operator=(String && s)
{
	if (this == &s)
		return *this;
	delete [] data;
	size = std::exchange(s.size, 0);
	data = std::exchange(s.data, nullptr);

	std::cout << "Move assignment" << std::endl;
	return *this;
}

String String::operator+(const String & s)
{
	String result(*this);
	result.append(s);
	return result;
}

String & String::operator+=(const String & s)
{
	return this->append(s);
}

bool String::operator==(const String & s) const
{
	return !(*this != s);
}

bool String::operator!=(const String & s) const
{
	return this->compare(s);
}

String & String::append(const String & s)
{
	return this->insert(size, s);
}

int String::compare(const String & s) const
{
	size_t comp_len = size < s.size ? size : s.size;
	int diff = 0;
	for (size_t i = 0; i < comp_len; ++i)
	{
		diff = data[i] -  (s.data)[i];
		if (diff)
			return diff;
	}
	if (size == s.size)
		return 0;
	else
		return size - s.size;
}

size_t String::length() const
{
	return size;
}

void String::resize(size_t n, char c)
{
	if (size == n)
	{
		return ;
	}
	char * new_data = new char[n];
	if (n < size)
	{
		strncpy(new_data, data, n);
	}
	else
	{
		strncpy(new_data, data, size);
		memset(new_data + size, c, n - size);
	}
	size = n;
	delete [] data;
	data = new_data;
	new_data = nullptr;
}

void String::clear()
{
	size = 0;
	delete [] data;
	data = nullptr;
}

void String::swap(String & s)
{
	s.size = std::exchange(size, s.size);
	s.data = std::exchange(data, s.data);
}

size_t String::substr(const String & s) const
{
	if (size < s.size)
		return -1;		// size_t max (npos)
	if (s.size == 0)
		return 0;
	for(size_t i = 0; i <= size - s.size; ++i)
	{
		if (!strncmp(data + i, s.data, s.size))
			return i;
	}
	return -1;
}

String & String::insert(size_t pos, const String & s)
{
	if (pos > size)
	{
		throw std::out_of_range("insert() pos is greater than String size");
	}
	if (this == &s)
	{
		char * new_data = new char[size + size];
		strncpy(new_data, data, pos);
		strncpy(new_data + pos, data, size);
		strncpy(new_data + pos + size, data + pos, size - pos);
		size += size;
		delete [] data;
		data = new_data;
		return *this;
	}
	size_t old_size = size;
	this->resize(size + s.size);
	memmove(data + pos + s.size, data + pos, old_size - pos);
	strncpy(data + pos, s.data, s.size);
	return *this;
}

String & String::insert(size_t pos, char c)
{
	// TODO think about adding constructor with char parameter 
	//		instead of this method
	String temp("a");
	temp.data[0] = c;
	try {
		this->insert(pos, temp);
	} catch(std::out_of_range & exc) {
		throw exc;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, const String & str)
{
	// TODO think about null-terminating String.data
	for(size_t i = 0; i < str.size; ++i)
		out << str.data[i];
	return out;
}

std::istream & operator>>(std::istream & in, String & str)
{
	str.clear();
	char c;
	while(isspace(c = in.get()))
		;
	// TODO make buffer
	size_t pos = 0;
	str.insert(pos++, c);
	while(in.get(c) && !isspace(c))
	{
		str.insert(pos++, c);
	}
	return in;
}
