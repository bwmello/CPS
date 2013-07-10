#include "Rectangle.h"
#include <iostream>
using std::endl;

Rectangle::Rectangle(double width, double height) 
{
	_box_width = width;
	_box_height = height;
}

void Rectangle::draw(std::ostream & ostr, double x, double y)
{
	double starting_x = x - (_box_width / 2);
	double starting_y = y - (_box_height / 2);

	ostr << "gsave" << endl;
	ostr << "newpath" << endl;
	ostr << starting_x << " " << starting_y << " moveto" << endl;
	ostr << _box_width << " 0" << " rlineto" << endl;
	ostr << "0 " << _box_height << " rlineto" << endl;
	ostr << -_box_width << " 0" << " rlineto" << endl;
	ostr << "closepath" << endl;
	ostr << "stroke" << endl;
	ostr << "grestore" << endl;
}
    
double Rectangle::get_box_height()
{
	return _box_height;
}

double Rectangle::get_box_width()
{
	return _box_width;
}