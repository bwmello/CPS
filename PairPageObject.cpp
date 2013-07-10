#include "PairPageObject.h"
#include <algorithm>

PairPageObject::PairPageObject(object_ptr left_object, object_ptr right_object):_left_object(left_object), _right_object(right_object)
{
	_box_height = std::max(_left_object->get_box_height(), _right_object->get_box_height());
	_box_width = _left_object->get_box_width() + _right_object->get_box_width();
}

void PairPageObject::draw(std::ostream & ostr, double x, double y)
{
	double box_left_x = x - _box_width/2;
	_left_object->draw(ostr, box_left_x + (_left_object->get_box_width() / 2), y);

	double box_right_x = box_left_x + _box_width;
	_right_object->draw(ostr, box_right_x - (_right_object->get_box_width() / 2), y);
}

double PairPageObject::get_box_height()
{
	return _box_height;
}

double PairPageObject::get_box_width()
{
	return _box_width;
}