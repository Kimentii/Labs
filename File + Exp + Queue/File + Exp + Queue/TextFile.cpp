#pragma once
#include "TextFile.h"
#include "Exception.h"
template <class T>
TextFile<T>::TextFile() {}
template <class T>
TextFile<T>::TextFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
TextFile<T>::~TextFile()
{
	file.close();
}
template <class T>
void TextFile<T>::refresh()
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
void TextFile<T>::show_status()
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
void TextFile<T>::show()
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
	try
	{
		while (1)
		{
			(*this) >> buf;
			if (file.eof()) break;
			cout << buf << endl;
		}
	}
	catch (...)
	{
		throw;
	}
	file.clear();
	last_read_pos = lastRP;
}
template <class T>
void TextFile<T>::close()
{
	file.close();
}
template <class T>
bool TextFile<T>::open(const char* fn)
{
	file.close();
	file.open(fn, ios::in | ios::out);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::trunc);
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
bool TextFile<T>::is_open()
{
	return file.is_open();
}
template <class T>
bool TextFile<T>::eof()
{
	return file.eof();
}
template <class T>
bool TextFile<T>::empty()
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
void TextFile<T>::getline(char* s, int n, char c)
{
	if (file)
	{
		file.seekg(last_read_pos, ios::beg);
		file.getline(s, n, c);
		if (file.eof())
		{
			file.clear();
			file.seekg(last_read_pos, ios::beg);
			file.getline(s, n, EOF);
		}
		last_read_pos = file.tellg();
	}
	else
	{
		throw FileExp(10, "File isn't open.");
	}
}
template <class T>
int TextFile<T>::size()
{
	int size = 0;
	if (file.is_open())
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
		return size;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
T TextFile<T>::operator [] (int i)
{
	T buf;
	try
	{
		if (strlen(file_name) && (i < size()) && i >= 0)
		{
			file.seekg(0, ios::beg);
			while (i)
			{
				(*this) >> buf;
				i--;
			}
			file >> buf;
			if (file.eof())
			{
				throw end_of_file();
			}
			return buf;
		}
		else
		{
			throw FileExp(12, "There is no such element");
		}
	}
	catch (...)
	{
		throw;
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator << (const T& el)
{
	if (file.is_open())
	{
		file.seekp(last_write_pos, ios::beg);
		file << el << ' ';
		last_write_pos = file.tellp();
		return *this;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator >> (T& el)
{
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		throw end_of_file();
	}
	file.seekg(last_read_pos, ios::beg);
	file >> el;
	if (file.fail() && !file.eof())
	{
		throw FileExp(13, "Something is wrong with the information.");
	}
	last_read_pos = file.tellg();
	return *this;
}
template <class T>
TextFile<T>& TextFile<T>::operator << (const cQueue<T>& el)
{
	if (file.is_open())
	{
		file.seekp(last_write_pos, ios::beg);
		file << el << ' ';
		last_write_pos = file.tellp();
		return *this;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator >> (cQueue<T>& el)
{
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		throw end_of_file();
	}
	file.seekg(0, ios::beg);
	file >> el;
	if (file.fail() && !file.eof())
	{
		throw FileExp(13, "Something is wrong with the information.");
	}
	file.clear();
	file.seekg(last_read_pos, ios::beg);
	return *this;
}