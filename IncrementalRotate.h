#ifndef _INCREMENTALROTATE_H_
#define _INCREMENTALROTATE_H_

#include "PageObject.h"

class IncrementalRotate : public PageObject
{
public:
    IncrementalRotate(unsigned int rotation_increment, object_ptr mod_obj);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
	unsigned int _rotation_increment;
	
    object_ptr _modified_object; 
};

#endif //_INCREMENTALROTATE_H_