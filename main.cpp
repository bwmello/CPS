#include "PageObject.h" 
#include "StackedPageObject.h"
#include "Circle.h"
#include "OverlappedPageObject.h"
#include "PairPageObject.h"
#include "Rectangle.h"
#include "RotPageObject.h"
#include "ScaledPageObject.h"
#include "InvisibleBox.h"
#include "Donut.h"
#include "WarpedCircle.h"
#include "RotPageObject.h"
#include "Polygon.h"
#include "ColoredPageObject.h"
#include "IncrementalRotate.h"

#include <iostream>
#include <fstream>
using std::ofstream;



int main()
{
	object_ptr circle = make_shared<Circle>(100);
	object_ptr colorCircle = make_shared<ColoredPageObject>(0,1,0, circle);
	object_ptr rectangle = make_shared<Rectangle>(100, 70);
	object_ptr colorRectangle = make_shared<ColoredPageObject>(0,0,1, rectangle);
	object_ptr redRectangle = make_shared<ColoredPageObject>(1,0,0, rectangle);
	object_ptr invisible = make_shared<InvisibleBox>(100, 70);
	object_ptr pair = make_shared<PairPageObject>(colorRectangle, redRectangle);
	object_ptr stacked = make_shared<StackedPageObject>(invisible, redRectangle);
	object_ptr stacked2 = make_shared<StackedPageObject>(colorCircle, colorRectangle);
	object_ptr stacked3 = make_shared<StackedPageObject>(stacked, stacked2);
	object_ptr polygon = make_shared<Polygon>(5, 100);
	object_ptr ndonut = make_shared<Donut>(-100, 200, 10);
	object_ptr irotate = make_shared<IncrementalRotate>(1, polygon);
	object_ptr irotate2 = make_shared<IncrementalRotate>(10, polygon);
	object_ptr irotate3 = make_shared<IncrementalRotate>(10, stacked3);
	object_ptr irotate4 = make_shared<IncrementalRotate>(2, stacked3);

	object_ptr greenPolygonRotate = make_shared<ColoredPageObject>(.3,1,.3, irotate);
	object_ptr redPolyRotate = make_shared<ColoredPageObject>(1,0,0, irotate2);

	object_ptr triangle = make_shared<Polygon>(3, 100);
	object_ptr pairTriangle = make_shared<PairPageObject>(triangle, triangle);
	object_ptr irotate5 = make_shared<IncrementalRotate>(6, pairTriangle);

	object_ptr overlap = make_shared<OverlappedPageObject>(polygon, stacked3);
	object_ptr irotate6 = make_shared<IncrementalRotate>(36, overlap);

	object_ptr irotate7 = make_shared<IncrementalRotate>(6, overlap);

	object_ptr irotate8 = make_shared<IncrementalRotate>(18, ndonut);

	ofstream myfile;
	myfile.open ("example.ps");

	PairPageObject two(rectangle, stacked3);
	two.draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	OverlappedPageObject touchingYouTouchingMe(circle, stacked3);
	touchingYouTouchingMe.draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	polygon->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;
	ScaledPageObject scale(1, .5, polygon);
	scale.draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;
	RotPageObject rotate(45, polygon);
	rotate.draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;
	ColoredPageObject greenPoly(.3,1,.3,polygon);
	greenPoly.draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	object_ptr warped = make_shared<WarpedCircle>(60, 45, 200);
	warped->draw(myfile, 250, 250);
	myfile << "showpage" << std::endl;

	object_ptr irotateWarped = make_shared<IncrementalRotate>(10, warped);
	irotateWarped->draw(myfile, 250, 250);
	myfile << "showpage" << std::endl;

	Donut donut(5, 100, 10);
	donut.draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	greenPolygonRotate->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	irotate->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	redPolyRotate->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	ndonut->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	irotate3->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;
	
	irotate4->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	irotate5->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	overlap->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	irotate6->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	irotate7->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;

	irotate8->draw(myfile, 300, 300);
	myfile << "showpage" << std::endl;


	myfile.close();
    return 0; 
}