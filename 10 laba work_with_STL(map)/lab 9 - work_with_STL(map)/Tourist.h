#pragma once
#include "Human.h"
struct Travel																//���� �����������
{
	char Date[SIZE];														//����
	char Country[SIZE];														//������
};
class Tourist : virtual public Human
{
protected:
	Travel m_Travels[NUM];													//������ ��������(�����������)
public:
	Tourist(const char* n = "", const char* sn = "", const char* mn = "", int y = 0);
	const Travel* const GetTravels();										//����������� ������� �����������
	bool AddTravel(const char* c, const char* d);							//���������� �����������
	bool DelTravel(const char* c = "", const char* d = "");					//�������� �����������
	friend ostream& operator << (ostream& os, const Tourist& aT);			//���������� ������
	friend istream& operator >> (istream& is, Tourist& aTur);				//���������� �����
};