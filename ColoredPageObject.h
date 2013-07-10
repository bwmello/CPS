#ifndef _COLOREDPAGEOBJECT_H_
#define _COLOREDPAGEOBJECT_H_

#include "PageObject.h"

class ColoredPageObject : public PageObject
{
public:
    ColoredPageObject(double red, double green, double blue, object_ptr mod_obj);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	double _red;
	double _blue;
	double _green;
	
	double _box_height;
	double _box_width;
	
    object_ptr _modified_object;
};

#endif //_COLOREDPAGEOBJECT_H_