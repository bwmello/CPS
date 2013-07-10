#include "RotPageObject.h"
#include <algorithm> 

RotPageObject::RotPageObject(double rotation_angle, object_ptr mod_obj): _rotation_angle(rotation_angle), _modified_object(mod_obj)
{
	if(rotation_angle == 90 || rotation_angle == 270)
	{
		_box_height = _modified_object -> get_box_width();

		_box_width = _modified_object -> get_box_height();
	}
	else
	{
		_box_height = _modified_object -> get_box_height();
		
		_box_width = _modified_object -> get_box_width();
	}
}

void RotPageObject::draw(std::ostream & ostr, double x, double y)
{
	ostr << "gsave\n";
	ostr << x << " " << y << " translate\n";
	ostr << _rotation_angle << " rotate\n";
    _modified_object -> draw(ostr, 0, 0);
	ostr << "grestore\n";
}

double RotPageObject::get_box_height()
{
    return _box_height;
}

double RotPageObject::get_box_width()
{
    return _box_width;
}