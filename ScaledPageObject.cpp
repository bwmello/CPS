#include "ScaledPageObject.h"
#include <algorithm> 

ScaledPageObject::ScaledPageObject(double xscale, double yscale, object_ptr mod_obj): _x_scale(xscale), _y_scale(yscale), _modified_object(mod_obj)
{
    _box_height = _y_scale * (_modified_object -> get_box_height());
	
   	_box_width = _x_scale * (_modified_object -> get_box_width());
}

void ScaledPageObject::draw(std::ostream & ostr, double x, double y)
{
	ostr << "gsave\n";
	ostr << x << " " << y << " translate\n";
	ostr << _x_scale << " " << _y_scale << " scale\n";
    _modified_object -> draw(ostr, 0, 0);
	ostr << "grestore\n";
}

double ScaledPageObject::get_box_height()
{
    return _box_height;
}

double ScaledPageObject::get_box_width()
{
    return _box_width;
}