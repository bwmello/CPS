#include "Polygon.h"
#include <algorithm> 
#include <math.h> 

#define PI 3.14159265

Polygon::Polygon(unsigned int numb_sides, double side_length): _numb_sides(numb_sides), _side_length(side_length)
{
	if(numb_sides % 2)
	{
		_box_height = side_length * ((1 + cos(PI/numb_sides)) / (2 * sin(PI/numb_sides)));
		
		_box_width = (side_length * sin(PI * ( numb_sides - 1) / (2 * numb_sides))) / sin(PI/numb_sides);
	}
	else if( ! (numb_sides % 4) )
	{
		_box_height = side_length * (cos(PI/numb_sides)) / (sin(PI/numb_sides));
		
		_box_width = (side_length * cos(PI / numb_sides)) / sin(PI/numb_sides);
	}
	else
	{
		_box_height = side_length * (cos(PI/numb_sides)) / (sin(PI/numb_sides));
		
		_box_width = side_length / (sin(PI/numb_sides));
	}
}

void Polygon::draw(std::ostream & ostr, double x, double y)
{
	double x_start_point = x - _side_length / 2.0;
	
	double angle = 0; 
	
	angle = 360.0 / _numb_sides;
	
	ostr << "gsave\n";
	ostr << "newpath\n";
	ostr << x_start_point << " " << y - (_box_height / 2) << " moveto\n";
	for(auto side = 1; side <= _numb_sides ; side ++)
	{
		ostr << _side_length << " " << 0 << " rlineto\n";
		ostr << angle << " rotate\n"; 
	}
	ostr << "stroke\n";
	ostr << "grestore\n";
}

double Polygon::get_box_height()
{
    return _box_height;
}

double Polygon::get_box_width()
{
    return _box_width;
}