#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
const int NUM = 1;
using namespace std;
class Human
{
protected:
	char m_Name[80];
	char m_SurName[80];
	char m_MiddleName[80];
	int m_YearOfBirth;
public:
	Human(const char* n = "", const char* sn = "", const char* mn = "", int y = 0);
	const char* const GetName();
	const char* const GetSurName();
	const char* const GetMiddleName();
	int GetYear();
	friend ostream& operator << (ostream& os, const Human& aHum);
	//friend istream& operator >> (istream& is, Human& aHum);
};