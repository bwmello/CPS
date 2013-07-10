#include "Circle.h"
#include <iostream>
using std::endl;

Circle::Circle(double radius):_radius(radius)
{
	_box_height = radius * 2;
	_box_width = radius * 2;
}
void Circle::draw(std::ostream & ostr, double x, double y)
{
	ostr << "gsave" << endl;
	ostr << "newpath" << endl;
	ostr << x << " " << y << " " << _radius << " 0" << " 360" << " arc" << endl;
	ostr << "stroke" << endl;
	ostr << "grestore" << endl;
}

double Circle::get_box_height()
{
	return _box_height;
}

double Circle::get_box_width()
{
	return _box_width;
}

double Circle::get_radius()
{
	return _radius;
}