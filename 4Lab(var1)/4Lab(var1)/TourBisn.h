#pragma once
#include "Businessman.h"
#include "Tourist.h"
class TourBisn : public Businessman, public Tourist
{
private:
	int m_Address[NUM];
public:
	TourBisn(const char* n = "", const char* sn = "", const char* mn = "", int y = 0, int l = 0, int p = 0);
	friend ostream& operator << (ostream& os, const TourBisn& aTB);
};