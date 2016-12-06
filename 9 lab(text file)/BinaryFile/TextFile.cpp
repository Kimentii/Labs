#include "TextFile.h"
template <class T>
TextFile<T>::TextFile() {}
template <class T>
TextFile<T>::TextFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{
	file.open(fn, ios::in | ios::out | ios::trunc);
	if (!file) throw 1;
}
template <class T>
TextFile<T>::~TextFile()
{
	file.close();
}
template <class T>
bool TextFile<T>::open(const char* fn)
{
	file.close();
	file.open(fn, ios::in | ios::out | ios::trunc);
	if (!file)
	{
		return false;
	}
	else
	{
		strcpy(file_name, fn);
		last_read_pos = 0;
		last_write_pos = 0;
		return true;
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
		throw 1;
	}
}
template <class T>
int TextFile<T>::size()
{
	int size = 0;
	if (file)
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
	}
	return size;
}
template <class T>
T TextFile<T>::operator [] (int i)
{

}
template <class T>
TextFile<T>& TextFile<T>::operator << (const T& el)
{
	if (file)
	{
		file.seekp(last_write_pos, ios::beg);
		file << el << ' ';
		last_write_pos = file.tellp();
		return *this;
	}
	else
	{
		throw 1;
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator >> (T& el)
{
	file.seekg(last_read_pos, ios::beg);
	file >> el;
	if (file.eof())
	{
		throw 1;
	}
	else
	{
		last_read_pos = file.tellg();
		return *this;
	}
}