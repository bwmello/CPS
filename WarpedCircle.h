#ifndef _WARPEDCIRCLE_H_
#define _WARPEDCIRCLE_H_

#include "PageObject.h"
#include "Circle.h"
#include <cmath>

class WarpedCircle : public PageObject
{
public:
	WarpedCircle(double radius, double direction, double distance);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	Circle _circle;
	double _direction; //in degrees, 0 to 360
	double _distance;
};

#endif //_WARPEDCIRCLE_H_