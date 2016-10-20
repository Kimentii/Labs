#pragma once
#include "Human.h"
struct Travel
{
	int Date;
	char Country[80];
};
class Tourist : virtual public Human
{
protected:
	Travel m_Travels[NUM];
	int m_PassportID;
public:
	Tourist(const char* n = "", const char* sn = "", const char* mn = "", int y = 0, int p = 0);
	friend ostream& operator << (ostream& os, const Tourist& aT);
};