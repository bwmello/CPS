#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "PageObject.h"

class Circle : public PageObject
{
public:
	Circle(double radius);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
	double get_radius();
    
private:
	double _radius;
};

#endif //_CIRCLE_H_