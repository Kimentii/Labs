#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
int main()
{
	Shape* p;
	Triangle T(0,0,2,4,4,0);
	T.CountArea();
	T.Print();
	system("pause");
	return 0;
}