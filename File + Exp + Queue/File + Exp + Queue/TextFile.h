#pragma once
#include "File.h"
#include "Queue.h"
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
	void refresh();
	void show_status();
	void show();
	void close();
	bool open(const char* fn);
	bool is_open();
	bool eof();
	bool empty();
	void getline(char* s, int n, char c = ' ');
	int size();
	T operator [] (int i);
	TextFile& operator << (const T& el);
	TextFile& operator >> (T& el);
	TextFile& operator << (const cQueue<T>& el);
	TextFile& operator >> (cQueue<T>& el);
};