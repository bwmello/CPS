#include "OverlappedPageObject.h"

OverlappedPageObject::OverlappedPageObject(object_ptr first_obj, object_ptr second_obj): _first_object(first_obj), _second_object(second_obj)
{
	if( first_obj -> get_box_height() >= second_obj -> get_box_height() )
		_box_height = first_obj -> get_box_height();
	else
		_box_height = second_obj -> get_box_height();
	if( first_obj -> get_box_width() >= second_obj -> get_box_width() )
		_box_width = first_obj -> get_box_width();
	else
		_box_width = second_obj -> get_box_width();
}

void OverlappedPageObject::draw(std::ostream & ostr, double x, double y)
{
    _first_object -> draw(ostr, x, y);
    _second_object -> draw(ostr, x, y);
}

double OverlappedPageObject::get_box_height()
{
    return _box_height;
}

double OverlappedPageObject::get_box_width()
{
    return _box_width;
}