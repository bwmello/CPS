#ifndef _ROTPAGEOBJECT_H_
#define _ROTPAGEOBJECT_H_

#include "PageObject.h"

class RotPageObject : public PageObject
{
public:
    RotPageObject(double rotation_angle, object_ptr mod_obj);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	double _rotation_angle;
	
    object_ptr _modified_object; 
};

#endif //_ROTPAGEOBJECT_H_