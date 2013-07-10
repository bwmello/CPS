#include "Square.h"
#include <iostream>
using std::endl;

Square::Square(double length): _polygon(4, length)
{
	_box_width = length;
	_box_height = length;

}

void Square::draw(std::ostream & ostr, double x, double y)
{
	_polygon.draw(ostr, x,y);
}
    
double Square::get_box_height()
{
	return _box_height;
}

double Square::get_box_width()
{
	return _box_width;
}