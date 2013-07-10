#ifndef PAIR_PAGE_OBJECT_H_
#define PAIR_PAGE_OBJECT_H_

#include "PageObject.h"

class PairPageObject : public PageObject
{
public:
	PairPageObject(object_ptr left_object, object_ptr right_object);

	void draw(std::ostream & ostr, double x, double y) override;

	double get_box_height() override;
    double get_box_width() override; 

private:
	object_ptr _left_object;
	object_ptr _right_object;
};

#endif // PAIR_PAGE_OBJECT_H_