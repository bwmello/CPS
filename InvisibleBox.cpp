#include "InvisibleBox.h"
#include <iostream>
using std::endl;

InvisibleBox::InvisibleBox(double width, double height) 
{
	_box_width = width;
	_box_height = height;
}

void InvisibleBox::draw(std::ostream & ostr, double x, double y)
{
	unsigned int starting_x = x - (_box_width / 2);
	unsigned int starting_y = y - (_box_height / 2);

	ostr << "gsave" << endl;
	ostr << "newpath" << endl;
	ostr << starting_x << " " << starting_y << " moveto" << endl;
	ostr << _box_width << " 0" << " rlineto" << endl;
	ostr << "0 " << _box_height << " rlineto" << endl;
	ostr << -_box_width << " 0" << " rlineto" << endl;
	ostr << "closepath" << endl;
	ostr << "grestore" << endl;
}
    
double InvisibleBox::get_box_height()
{
	return _box_height;
}

double InvisibleBox::get_box_width()
{
	return _box_width;
}