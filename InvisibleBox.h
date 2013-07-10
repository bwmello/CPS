#ifndef _INVISIBLEBOX_H_
#define _INVISIBLEBOX_H_

#include "PageObject.h"

class InvisibleBox : public PageObject
{
public:
	InvisibleBox(double width, double height);
    void draw(std::ostream & ostr, double x, double y) override;
    
    double get_box_height() override;
    double get_box_width() override;
    
private:
};

#endif //_INVISIBLEBOX_H_