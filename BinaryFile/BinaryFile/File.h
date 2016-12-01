#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;
class File
{
protected:
	char file_name[80];
public:
	File(const char* fn = "");
	~File() {}
};