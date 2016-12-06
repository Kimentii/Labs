#pragma once
#include "File.h"
template <class T>
class TextFile : File
{
	streampos last_read_pos;
	streampos last_write_pos;
	fstream file;
public:
	TextFile();
	TextFile(const char* fn);
	~TextFile();
	bool open(const char* fn);
	void getline(char* s, int n, char c = ' ');
	int size();
	T operator [] (int i);
	TextFile& operator << (const T& el);
	TextFile& operator >> (T& el);
};