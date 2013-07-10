#include "ColoredPageObject.h"
#include <algorithm> 

double clamp(double lower, double value, double higher)
{
	if( value < lower )
		return lower;
	else if( value > higher )
		return higher;
	else
		return value; 
	
}

ColoredPageObject::ColoredPageObject(double red, double green, double blue, object_ptr mod_obj):_modified_object(mod_obj)
{
    _box_height = (_modified_object -> get_box_height());
   	_box_width =  (_modified_object -> get_box_width());
	
	_red = clamp(0.0, red, 1.0);
	_blue = clamp(0.0 ,blue, 1.0);
	_green = clamp(0.0, green, 1.0);
}

void ColoredPageObject::draw(std::ostream & ostr, double x, double y)
{
	ostr << "gsave\n";
	ostr << x << " " << y << " translate\n";
	ostr << _red << " " <<  _green << " " << _blue << " setrgbcolor\n";
    _modified_object -> draw(ostr, 0, 0);
	ostr << "grestore\n";
}

double ColoredPageObject::get_box_height()
{
    return _box_height;
}

double ColoredPageObject::get_box_width()
{
    return _box_width;
}