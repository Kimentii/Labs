#pragma once
#include "BinaryFile.h"
#include "Exception.h"
#include "Queue.h"
template <class T>
BinaryFile<T>::BinaryFile() {}
template <class T>
BinaryFile<T>::BinaryFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
BinaryFile<T>::~BinaryFile()
{
	file.close();
}
template <class T>
void BinaryFile<T>::refresh()
{
	if (file.is_open())
	{
		file.clear();
		last_read_pos = 0;
		last_write_pos = 0;
		file.seekg(last_read_pos, ios::beg);
		file.seekp(last_write_pos, ios::beg);
	}
}
template <class T>
void BinaryFile<T>::show_status()
{
	if (file.is_open())
	{
		cout.setf(ios::right);
		cout << setw(20) << "is open";
		cout << setw(20) << "end of file";
		cout << setw(20) << "size(elements)" << endl;
		cout << setw(20) << file.is_open();
		cout << setw(20) << file.eof();
		cout << setw(20) << size() << endl;
		cout.setf(ios::left);
	}
	else
	{
		cout << "File isn't open." << endl;
	}
}
template <class T>
void BinaryFile<T>::show()
{
	T buf;
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		file.clear();
	}
	streampos lastRP = last_read_pos;
	file.seekg(0, ios::beg);
	while (read(&buf))
	{
		cout << buf << endl;
	}
	file.clear();
	last_read_pos = lastRP;
}
template <class T>
void BinaryFile<T>::close()
{
	file.close();
}
template <class T>
bool BinaryFile<T>::write(const T& el, int n)
{
	if (file.is_open())
	{
		file.seekp(last_write_pos, ios::beg);
		file.write(reinterpret_cast<const char*>(&el), n * sizeof(T));
		last_write_pos = file.tellp();
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
bool BinaryFile<T>::open(const char* fn)
{
	file.close();
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
		if (!file)
		{
			return false;
		}
	}
	strcpy(file_name, fn);
	last_read_pos = 0;
	last_write_pos = 0;
	return true;
}
template <class T>
bool BinaryFile<T>::is_open()
{
	return file.is_open();
}
template <class T>
bool BinaryFile<T>::eof()
{
	return file.eof();
}
template <class T>
int BinaryFile<T>::size()
{
	int size = 0;
	if (file.is_open())
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
		size /= sizeof(T);
		return size;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
bool BinaryFile<T>::read(T* el, int n)
{
	if (!file.is_open())
	{
		return false;
	}
	file.seekg(last_read_pos, ios::beg);
	file.read(reinterpret_cast<char*>(el), n * sizeof(T));
	if (file.eof())
	{
		return false;
	}
	last_read_pos = file.tellg();
	return true;
}
template <class T>
bool BinaryFile<T>::empty()
{
	try
	{
		if (size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		throw;
	}
}
template <class T>
T BinaryFile<T>::operator [] (int i)
{
	T buf;
	if (file.is_open() && (i < size()) && i >= 0)
	{
		file.seekg(i * sizeof(T), ios::beg);
		file.read(reinterpret_cast<char*>(&buf), sizeof(T));
		file.seekg(last_read_pos, ios::beg);
		return buf;
	}
	else
	{
		throw FileExp(12, "There is no such element");
	}
}
template <class T>
void BinaryFile<T>::read_queue(cQueue<T>& q)
{
	T buf;
	q.clear();
	if (!is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		file.clear();
	}
	streampos lastRP = last_read_pos;
	file.seekg(0, ios::beg);
	while (read(&buf))
	{
		q.PushBack(buf);
	}
	file.clear();
	last_read_pos = lastRP;
}