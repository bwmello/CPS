#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "PageObject.h"

class Polygon : public PageObject
{
public:
    Polygon(unsigned int _numb_sides, double side_length);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	unsigned int _numb_sides;
	double _side_length;
	
    object_ptr _modified_object;
};

#endif //_POLYGON_H_