#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <iostream>
using namespace std;
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
		//cout << "Shape constructor." << endl;
		strcpy_s(Name, s);
	}
	virtual ~Shape() {}
	virtual void Print() = 0;
	virtual double CountVolume() = 0;
	virtual double CountArea() = 0;
};
#endif