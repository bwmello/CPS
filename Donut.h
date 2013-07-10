#ifndef _DONUT_H_
#define _DONUT_H_

#include "PageObject.h"

class Donut : public PageObject
{
public:
	Donut(double inner_radius, double outer_radius, unsigned int rotation_increment);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	double _inner_radius;
	double _outer_radius;
	unsigned int _rotation_increment;
};

#endif //_DONUT_H_