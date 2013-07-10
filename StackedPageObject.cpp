#include "StackedPageObject.h"
#include <algorithm> 

StackedPageObject::StackedPageObject(object_ptr bottom_obj, object_ptr top_obj): _bottom_object(bottom_obj) , _top_object(top_obj)
{
    _box_height = _bottom_object -> get_box_height() + _top_object -> get_box_height();
	
   	_box_width = std::max(_bottom_object -> get_box_width(), _top_object -> get_box_width()); 
}

void StackedPageObject::draw(std::ostream & ostr, double x, double y)
{
    double box_low_y = y - _box_height / 2;
    _bottom_object -> draw(ostr, x, box_low_y + (_bottom_object->get_box_height() / 2) );
    
    double box_top_y = box_low_y + _box_height;
    _top_object -> draw(ostr, x, ( box_top_y - (_top_object->get_box_height() / 2) ) );
}

double StackedPageObject::get_box_height()
{
    return _box_height;
}

double StackedPageObject::get_box_width()
{
    return _box_width;
}