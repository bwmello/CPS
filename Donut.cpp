#include "Donut.h"
#include <iostream>
using std::endl;

Donut::Donut(double inner_radius, double outer_radius, unsigned int rotation_increment):_inner_radius(inner_radius),
	   _outer_radius(outer_radius), _rotation_increment(rotation_increment)
{
	_box_height = _outer_radius * 2;
	_box_width = _outer_radius * 2;
}
void Donut::draw(std::ostream & ostr, double x, double y)
{
	double radius = (_outer_radius - _inner_radius) / 2;
	ostr << "0 " << _rotation_increment << " 360 {" << endl;
	ostr << "newpath" << endl;
	ostr << "gsave" << endl;
	ostr << x << " " << y << " " << "translate" << endl;
	ostr << "rotate" << endl;
	ostr << "0 " << radius + _inner_radius << " " << radius << " 0" << " 360" << " arc" << endl;
	ostr << "stroke" << endl;
	ostr << "grestore" << endl;
	ostr << "} for" << endl;
}

double Donut::get_box_height()
{
	return _box_height;
}

double Donut::get_box_width()
{
	return _box_width;
}