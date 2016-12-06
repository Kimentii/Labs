#pragma once
#include "File.h"
template <class T>
class BinaryFile : public File
{
	streampos last_read_pos;
	streampos last_write_pos;
	fstream file;
public:
	BinaryFile();
	BinaryFile(const char* fn);
	~BinaryFile();
	bool write(const T& el, int n = 1);
	bool read(T* el, int n = 1);
	bool open(const char* fn);
	int size();
	T operator [] (int i);
	BinaryFile& operator << (const T& el);
	BinaryFile& operator >> (T& el);
};