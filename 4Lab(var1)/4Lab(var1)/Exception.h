#pragma once
const int LEN = 80;
class Exception
{
protected:
	int NumOfError;
public:
	Exception(int i = 0) : NumOfError(i) { }
	virtual int error() { return NumOfError; }
	virtual char* what() = 0;
};
class InputExp : public Exception
{
	char desc[LEN];
public:
	InputExp() : Exception(1) { strcpy(desc, "wrong input."); }
	int error() { return Exception::error(); }
	char* what() { return desc; }
};
class not_int : public InputExp
{
	char desc[LEN];
public:
	not_int() { strcpy(desc, "wrong input, please enter integer value."); NumOfError = 3; }
	int error() { return Exception::error(); }
	char* what() { return desc; }
};
class not_eng : public InputExp
{
	char desc[LEN];
public:
	not_eng() { strcpy(desc, "wrong input, please use English."); NumOfError = 4; }
	int error() { return Exception::error(); }
	char* what() { return desc; }
};
class out_of_size : public InputExp
{
	char desc[LEN];
public:
	out_of_size() { strcpy(desc, "wrong input, too much or too little."); NumOfError = 5; }
	int error() { return Exception::error(); }
	char* what() { return desc; }
};
//class QueueExp : public Exception
//{
//public:
//	void what();
//};
//class wrong_element : public QueueExp
//{
//public:
//	void what();
//};