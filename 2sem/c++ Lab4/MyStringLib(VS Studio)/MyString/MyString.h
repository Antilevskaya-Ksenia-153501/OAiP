#pragma once

#ifndef _MYSTRING_H
#define _MYSTRING_H

#ifdef MYSTRING_EXPORTS
#define MYSTRING_API __declspec(dllexport)
#else
#define MYSTRING_API __declspec(dllimport)
#endif

class _declspec(dllexport) MyString
{
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;
	~MyString();

	MyString& operator= (const MyString& other);
	MyString operator+(const MyString& other);
	MyString operator+ (const char* other);
	bool operator== (const MyString& other);
	bool operator!= (const MyString& other);
	bool operator< (const MyString& other);
	bool operator<= (const MyString& other);
	bool operator> (const MyString& other);
	bool operator>= (const MyString& other);

	char& operator[] (int index);
	char& at(int index);

	bool Empty() const;
	char* getText();
	
	size_t Size();
	size_t Length() const;

	MyString& Erase(const size_t& position, const size_t& n);
	size_t Copy(char* temp, const size_t& len, const size_t& pos) const;
	void Swap(MyString& other);
	
	MyString& Assign(const MyString& other);
	MyString& Assign(const char* other);
	MyString& Assign(const char* other, const size_t& n);
	MyString& Assign(const size_t& n, const char symbol);
	MyString& Assign(const MyString& other, const size_t& pos, const size_t& len);

	MyString& Append(const MyString& other);
	MyString& Append(const char* other);
	MyString& Append(const MyString& other, const size_t& pos, const size_t& len);
	MyString& Append(const char* other, const size_t& n);
	MyString& Append(const size_t& n, const char symbol);

	MyString& Insert(const size_t& pos, const MyString& other);
	MyString& Insert(const size_t& pos, const char* other);

	MyString& Replace(const size_t& pos, const size_t& len, const MyString& other);
	MyString& Replace(const size_t& pos, const size_t& len, const char* other);

	void Clear();

	void ExpandMemory(const size_t& n);
	void push_back(const char& symbol);

	friend std::ostream& operator<< (std::ostream& os, const MyString& other);
	friend std::istream& operator>> (std::istream& is, MyString& other);

private:
	char* str;
	int size;
};

std::ostream& operator<< (std::ostream& os, const MyString& other);
std::istream& getline(std::istream& is, MyString& other, const char& stop);
std::istream& operator>> (std::istream& is, MyString& other);
#endif //_IMYSTRING_H
