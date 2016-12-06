#include "BinaryFile.h"
template <class T>
BinaryFile<T>::BinaryFile() {}
template <class T>
BinaryFile<T>::BinaryFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{
	file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	if (!file) throw 1;
}
template <class T>
BinaryFile<T>::~BinaryFile()
{
	file.close();
}
template <class T>
bool BinaryFile<T>::write(const T& el, int n)
{
	if (file)
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
	file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
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
int BinaryFile<T>::size()
{
	int size = 0;
	if (file)
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
		size /= sizeof(T);
	}
	return size;
}
template <class T>
bool BinaryFile<T>::read(T* el, int n)
{
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
T BinaryFile<T>::operator [] (int i)
{
	T buf;
	if (file && (i < size()) && i >= 0)
	{
		file.seekg(i * sizeof(T), ios::beg);
		file.read(reinterpret_cast<char*>(&buf), sizeof(T));
		file.seekg(last_read_pos, ios::beg);
		return buf;
	}
	else
	{
		throw 1;
	}
}
template <class T>
BinaryFile<T>& BinaryFile<T>::operator << (const T& el)
{
	(*this).write(el);
	return *this;
}
template <class T>
BinaryFile<T>& BinaryFile<T>::operator >> (T& el)
{
	(*this).read(&el);
	return *this;
}