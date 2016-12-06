#pragma once
#include "TextFile.h"
#include "Exception.h"
template <class T>
TextFile<T>::TextFile() {}									//Конструктор по умолчанию
template <class T>
TextFile<T>::TextFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{															//Конструктор с параметром
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
TextFile<T>::~TextFile()									//Деструктор
{
	file.close();
}
template <class T>
void TextFile<T>::refresh()									//Обновление файла
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
void TextFile<T>::show_status()								//Вывод состояния файла
{
	if (file.is_open())
	{
		cout.setf(ios::right);
		cout << setfill('-') << setw(120) << '-' << endl << setfill(' ');
		cout << setw(20) << "is open";
		cout << setw(20) << "end of file";
		cout << setw(20) << "size(elements)";
		cout << setw(20) << "read position";
		cout << setw(20) << "write position" << endl;
		cout << setw(20) << file.is_open();
		cout << setw(20) << file.eof();
		cout << setw(20) << size();
		cout << setw(20) << last_read_pos;
		cout << setw(20) << last_write_pos << endl;
		cout << setfill('-') << setw(120) << '-' << endl << setfill(' ');
		cout.setf(ios::left);
	}
	else
	{
		cout << "File isn't open." << endl;
	}
}
template <class T>
void TextFile<T>::show()									//Вывод содержимого файла
{
	T buf;
	bool file_end = false;
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		file.clear();
		file_end = true;
	}
	streampos lastRP = last_read_pos;
	last_read_pos = 0;
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
	if (file_end) file.clear(1);
	last_read_pos = lastRP;
}
template <class T>
void TextFile<T>::close()									//Закрытие файла
{
	file.close();
}
template <class T>
bool TextFile<T>::open(const char* fn)						//Открытие файла
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
bool TextFile<T>::is_open()									//true если файл открыт
{
	return file.is_open();
}
template <class T>
bool TextFile<T>::eof()										//true если конец файла
{
	return file.eof();
}
template <class T>
bool TextFile<T>::empty()									//true если файл пуст
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
void TextFile<T>::getline(char* s, int n, char c)			//Чтение строки из файла
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
int TextFile<T>::size()										//Возвращает размер файла
{
	int size = 0;
	bool end_file = false;
	if (file.eof())
	{
		end_file = true;
		file.clear();
	}
	if (file.is_open())
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
		size;
		if (end_file)
		{
			file.clear(1);
		}
		return size;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
T TextFile<T>::operator [] (int i)							//Возвращет любой элементй файла
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
TextFile<T>& TextFile<T>::operator << (const T& el)			//Перегрузка <<
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
TextFile<T>& TextFile<T>::operator >> (T& el)				//Перегрузка >>
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
{															//Перегрузка << для очереди
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
TextFile<T>& TextFile<T>::operator >> (cQueue<T>& el)		//Перегрузка >> для очереди
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
	try
	{
		file >> el;
	}
	catch (...)
	{
		throw;
	}
	if (file.fail() && !file.eof())
	{
		throw FileExp(13, "Something is wrong with the information.");
	}
	file.clear();
	file.seekg(last_read_pos, ios::beg);
	return *this;
}