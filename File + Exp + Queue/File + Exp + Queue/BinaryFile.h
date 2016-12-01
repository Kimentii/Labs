#pragma once
#include "File.h"
#include "Queue.h"
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
	void refresh();
	void show_status();
	void show();
	void close();
	bool write(const T& el, int n = 1);
	bool read(T* el, int n = 1);
	bool open(const char* fn);
	bool is_open();
	bool eof();
	bool empty();
	int size();
	T operator [] (int i);
	void read_queue(cQueue<T>& q);
};