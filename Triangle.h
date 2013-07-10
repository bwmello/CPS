#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Triangle.h"
#include "Polygon.h"

class Triangle : public PageObject
{
public:
	Triangle(double length);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;

private:
	Polygon _polygon; 
};

#endif //_TRIANGLE_H_