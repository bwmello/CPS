#include "Triangle.h"
#include <iostream>
using std::endl;

Triangle::Triangle(double length): _polygon(3, length)
{
	_box_width = length;
	_box_height = length;

}

void Triangle::draw(std::ostream & ostr, double x, double y)
{
	_polygon.draw(ostr, x,y);
}
    
double Triangle::get_box_height()
{
	return _box_height;
}

double Triangle::get_box_width()
{
	return _box_width;
}