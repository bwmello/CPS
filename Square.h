#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Square.h"
#include "Polygon.h"

class Square : public PageObject
{
public:
	Square(double length);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;

private:
	Polygon _polygon; 
};

#endif //_RECTANGLE_H_