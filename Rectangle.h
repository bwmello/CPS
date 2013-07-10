#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "PageObject.h"

class Rectangle : public PageObject
{
public:
	Rectangle(double width, double height);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;

private:
};

#endif //_RECTANGLE_H_