#include "IncrementalRotate.h"
#include <algorithm> 
#include <math.h>
using std::pow;

IncrementalRotate::IncrementalRotate(unsigned int rotation_increment, object_ptr mod_obj): _rotation_increment(rotation_increment),
					_modified_object(mod_obj)
{
    _box_height = 2 * (pow(_modified_object -> get_box_height(), 2) + pow(_modified_object -> get_box_width(), 2));
	
	_box_width = _box_height;
}

void IncrementalRotate::draw(std::ostream & ostr, double x, double y)
{
	double rotation_point_x = -_modified_object->get_box_width()/2;
	double rotation_point_y = -_modified_object->get_box_height()/2;
	ostr << "0 " << _rotation_increment << " 360 {\n";
	ostr << "newpath\n";
	ostr << "gsave\n";
	ostr << x << " " << y << " " << "translate\n";
	ostr << "rotate\n";
	_modified_object->draw(ostr, rotation_point_x, rotation_point_y);
	ostr << "grestore\n";
	ostr << "} for\n";
}

double IncrementalRotate::get_box_height()
{
    return _box_height;
}

double IncrementalRotate::get_box_width()
{
    return _box_width;
}