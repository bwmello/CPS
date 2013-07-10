#include "WarpedCircle.h"
#include <iostream>
using std::endl;
#define PI 3.14159265

WarpedCircle::WarpedCircle(double radius, double direction, double distance):_direction(direction),_distance(distance),_circle(radius)
{
	if(_circle.get_box_height()*.5 < sin(direction*PI/180)/distance) //The warp point is above or below the circle's box height
		_box_height = _circle.get_box_height()*.5 + sin(direction*PI/180)/distance;
	else															//The warp point is within the circle's box height
		_box_height = _circle.get_box_height();

	if(_circle.get_box_width()*.5 < cos(direction*PI/180)/distance) //The warp point is left or right of the circle's box width
		_box_width = _circle.get_box_width()*.5 + cos(direction*PI/180)/distance;
	else															//The warp point is within the circle's box width
		_box_width = _circle.get_box_width();
}

void WarpedCircle::draw(std::ostream & ostr, double x, double y)
{
	_circle.draw(ostr, x, y);

	ostr << "gsave" << endl;
	ostr << "newpath" << endl;
	ostr << x+cos((_direction+75)*PI/180)*_circle.get_radius() << " " << y+sin((_direction+75)*PI/180)*_circle.get_radius() << " moveto" << endl;
	ostr << x+cos(_direction*PI/180)*_distance << " " << y+sin(_direction*PI/180)*_distance << " lineto" << endl;
	ostr << x+cos((_direction-75)*PI/180)*_circle.get_radius() << " " << y+sin((_direction-75)*PI/180)*_circle.get_radius() << " lineto" << endl;
	ostr << "stroke" << endl;
	ostr << "grestore" << endl;
}

double WarpedCircle::get_box_height()
{
	return _box_height;
}

double WarpedCircle::get_box_width()
{
	return _box_width;
}