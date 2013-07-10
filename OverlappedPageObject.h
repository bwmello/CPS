#ifndef _OVERLAPPEDPAGEOBJECT_H_
#define _OVERLAPPEDPAGEOBJECT_H_

#include "PageObject.h"

class OverlappedPageObject : public PageObject
{
public:
    OverlappedPageObject(object_ptr first_obj, object_ptr second_obj);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override; 
    
private:
    object_ptr _first_object;
    object_ptr _second_object;
};

#endif