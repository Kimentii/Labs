#pragma once
#include "Businessman.h"
#include "Tourist.h"
class TourBisn : public Businessman, public Tourist
{
private:
	char** m_Address;															//������ �����(�������)
	int m_NumAddress;															//���������� �������
public:
	TourBisn(const char* n = "", const char* sn = "", const char* mn = "", int y = 0, int l = 0, int p = 0, int na = 0);
	TourBisn(const TourBisn&);													//����������� �����������
	~TourBisn();																//����������
	const char** const GetAddress();											//����������� ������� �����
	int GetNumAddress();														//����������� ���������� �����
	void AddAddress(const char* a);												//���������� ������
	bool DelAddress(const char* a);												//�������� ������
	TourBisn operator = (const TourBisn& aTB);
	friend ostream& operator << (ostream& os, const TourBisn& aTB);				//���������� ������
	friend istream& operator >> (istream& is, TourBisn& aTurBis);				//���������� �����
};