#pragma once
#include "BinaryFile.h"
#include "Exception.h"
#include "Queue.h"
#include <iomanip>
template <class T>
BinaryFile<T>::BinaryFile() {}									//����������� �� ���������
template <class T>
BinaryFile<T>::BinaryFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{																//����������� � ����������
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
BinaryFile<T>::~BinaryFile()									//����������
{
	file.close();												//�������� �����
}
template <class T>
void BinaryFile<T>::refresh()									//���������� �����
{
	if (file.is_open())											//���� ���� ������
	{
		file.clear();											//����� �����
		last_read_pos = 0;										//��������� ������� ������ � ������
		last_write_pos = 0;
		file.seekg(last_read_pos, ios::beg);
		file.seekp(last_write_pos, ios::beg);
	}
}
template <class T>
void BinaryFile<T>::show_status()								//������� ������ �����
{
	if (file.is_open())											//���� ���� ������
	{
		cout.setf(ios::right);
		cout << setfill('-') << setw(120) << '-' << endl << setfill(' ');
		cout << setw(20) << "is open";
		cout << setw(20) << "end of file";
		cout << setw(20) << "size(elements)";
		cout << setw(20) << "read position";
		cout << setw(20) << "write position" << endl;
		cout << setw(20) << file.is_open();
		cout << setw(20) << file.eof();							//����� ���� ����� �����
		cout << setw(20) << size();								//����� ������� �����
		cout << setw(20) << last_read_pos / sizeof(T);			//����� ��������� ������� ������
		cout << setw(20) << last_write_pos / sizeof(T) << endl;	//����� ��������� ������� �������
		cout << setfill('-') << setw(120) << '-' << endl << setfill(' ');
		cout.setf(ios::left);
	}
	else
	{
		cout << "File isn't open." << endl;						//���� ���� �� ������ �� ����� ��������� �� ����
	}
}
template <class T>
void BinaryFile<T>::show()										//����� ����������� �����
{
	T buf;														//�������� �������
	bool file_end = false;
	if (!file.is_open())										//���� ���� �� ������, ��
	{
		throw FileExp(11, "File isn't open.");					//��������� ������
	}
	if (file.eof())												//���� ����� �����
	{
		file.clear();											//������� �����
		file_end = true;
	}
	streampos lastRP = last_read_pos;
	last_read_pos = 0;
	while (read(&buf))											//����� ������ �����
	{
		cout << buf << endl;
	}
	file.clear();												//������� ����� ������
	if (file_end) file.clear(1);								//���� ��� ����� �����, �� ����������� ����� �����
	last_read_pos = lastRP;
}
template <class T>
void BinaryFile<T>::close()										//�������� �����
{
	file.close();
}
template <class T>
bool BinaryFile<T>::write(const T& el, int n)					//������ � ����
{
	if (file.is_open())											//���� ���� ������
	{
		file.seekp(last_write_pos, ios::beg);
		file.write(reinterpret_cast<const char*>(&el), n * sizeof(T));	//������ �� �����
		last_write_pos = file.tellp();							//���������� ������� ���������� ������
		return true;
	}
	else
	{
		return false;											//���� ���� ������ �� ���������� false
	}
}
template<class T>
bool BinaryFile<T>::open(const char* fn)						//������� �������� �����
{
	file.close();												//�������� ������� �����
	file.open(fn, ios::in | ios::out | ios::binary);			//������� �������� ��� ������������� �����
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);	//����� �������� ������ �����
		if (!file)
		{
			return false;
		}
	}
	strcpy(file_name, fn);										//���������� ��� �����
	last_read_pos = 0;											//������� ������ � ������ ������ � ������
	last_write_pos = 0;
	return true;
}
template <class T>
bool BinaryFile<T>::is_open()									//true ���� ���� ������
{
	return file.is_open();
}
template <class T>
bool BinaryFile<T>::eof()										//true ���� ����� �����
{
	return file.eof();
}
template <class T>
int BinaryFile<T>::size()										//���������� ������ �����
{
	int size = 0;
	bool end_file = false;										//���������� �������� �����
	if (file.eof())
	{
		end_file = true;
		file.clear();
	}
	if (file.is_open())											//���� ���� ������
	{
		file.seekg(0, ios::end);								//���������� ������� ������ � �����
		size = file.tellg();									//���������� � �������
		file.seekg(last_read_pos, ios::beg);
		size /= sizeof(T);										//����� �� ������ ��������
		if (end_file)
		{
			file.clear(1);										//���������� ���� ����� �����(���� �� ���)
		}
		return size;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
bool BinaryFile<T>::read(T* el, int n)							//������ �� �����
{
	if (!file.is_open() || file.eof())							//���� ���� ������ ��� ����� �����
	{
		return false;											//�� false
	}
	file.seekg(last_read_pos, ios::beg);						//���������� ������� ������ �� ��������� ������� ������
	file.read(reinterpret_cast<char*>(el), n * sizeof(T));		//��������� �������
	if (file.eof())
	{
		return false;
	}
	last_read_pos = file.tellg();
	return true;
}
template <class T>
bool BinaryFile<T>::empty()										//true ���� ���� ����
{
	try
	{
		if (size() == 0)										//���� ������ ����� ����
		{
			return true;										//�� ���������� true
		}
		else
		{
			return false;										//����� false
		}
	}
	catch (...)
	{
		throw;
	}
}
template <class T>
T BinaryFile<T>::operator [] (int i)							//������ � ������� �������� �����
{
	T buf;
	if (file.is_open() && (i < size()) && i >= 0)				//���� ��������� ������ �����
	{
		file.seekg(i * sizeof(T), ios::beg);
		file.read(reinterpret_cast<char*>(&buf), sizeof(T));	//��������� ���� �������
		file.seekg(last_read_pos, ios::beg);
		return buf;
	}
	else
	{
		throw FileExp(12, "There is no such element");
	}
}
template <class T>
void BinaryFile<T>::read_queue(cQueue<T>& q)					//������ ������� �� �����
{
	T buf;
	q.clear();
	if (!is_open())												//�������� �� �������� �����
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		file.clear();
	}
	streampos lastRP = last_read_pos;
	file.seekg(0, ios::beg);
	while (read(&buf))											//������ ������� �� �����
	{
		q.PushBack(buf);
	}
	file.clear();
	last_read_pos = lastRP;
}