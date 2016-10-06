#include <iostream>
using namespace std;
#pragma warning(disable : 4996);
//class Shape;
//class TwoDShape : public Shape {};
//class ThreeDShape : public Shape {};
//class Ractangle : public TwoDShape {};
//class Circle : public TwoDShape {};
//class Triangle : public TwoDShape {};
//class Cylinder : public ThreeDShape {};
//class Cube : public ThreeDShape {};
class Shape
{
protected:
	char Name[80];
public:
	Shape(char* s = "No name")
	{
		cout << "Shape constructor." << endl;
		strcpy(Name, s);
	}
	virtual void Print() = 0;
};