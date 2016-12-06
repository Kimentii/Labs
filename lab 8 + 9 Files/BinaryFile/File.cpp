#include "File.h"
File::File(const char* fn)
{
	strcpy(file_name, fn);
}