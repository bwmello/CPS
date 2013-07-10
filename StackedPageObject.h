#ifndef _STACKEDPAGEOBJECT_H_
#define _STACKEDPAGEOBJECT_H_

#include "PageObject.h"

class StackedPageObject : public PageObject
{
public:
    StackedPageObject(object_ptr bottom_obj, object_ptr top_obj);
    
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override; 
    
private:
    object_ptr _top_object;
    object_ptr _bottom_object;
};

#endif //_STACKEDPAGEOBJECT_H_