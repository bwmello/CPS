#ifndef _SCALEDPAGEOBJECT_H_
#define _SCALEDPAGEOBJECT_H_

#include "PageObject.h"

class ScaledPageObject : public PageObject
{
public:
    ScaledPageObject(double xscale, double yscale, object_ptr mod_obj);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	double _x_scale;
	double _y_scale; 
	
    object_ptr _modified_object;
};

#endif //_SCALEDPAGEOBJECT_H_