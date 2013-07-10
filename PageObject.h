
#ifndef _PAGEOBJECT_H_
#define _PAGEOBJECT_H_

#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <ostream> 

class PageObject {
public:
    virtual ~PageObject() = 0;

    virtual void draw(std::ostream & ostr, double x, double y) = 0;
    
    virtual double get_box_height() = 0;
    virtual double get_box_width() = 0;
    
protected:
    double _box_height;
    double _box_width;
};

typedef shared_ptr<PageObject> object_ptr;

#endif //_PAGEOBJECT_H_