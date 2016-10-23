#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
const int NUM = 5;
const int SIZE = 80;
using namespace std;
class Human
{
protected:
	char m_Name[SIZE];
	char m_SurName[SIZE];
	char m_MiddleName[SIZE];
	int m_YearOfBirth;
public:
	Human(const char* n = "", const char* sn = "", const char* mn = "", int y = 0);
	const char* const GetName();
	const char* const GetSurName();
	const char* const GetMiddleName();
	int GetYear();
	void SetName(const char* n);
	void SetSurName(const char* sn);
	void SetMiddleName(const char* mn);
	void SetYearOfBirth(int y);
	friend ostream& operator << (ostream& os, const Human& aHum);
	//friend istream& operator >> (istream& is, Human& aHum);
};