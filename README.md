CPS
===

CPS, short for "C++ to PostScript," allows users to specify drawings at a high level of abstraction, and output the drawings as PostScript.

Team
===
Charlie Carlson, Ruslan Kolesnik, Brent Mello


Files
===
PageObject.h
Base class for all other classes. 

Circle.cpp and Circle.h
Describes circle object. Constructor is Circle( double radius ). Creates a circle of radius in postscript units. 
 
Rectangle.cpp and Rectangle.h 
Describes rectangle object. Constructor is Rectangle( double width, double height). Creates a rectangle of passed height and width.  

Polygon.cpp and Polygon.h
Describes polygon object. Constructor is Polygon( unsigned int number_of_sides, double side_length). Creates a polygon of passed number_of_sides and side_length.  

Donut.cpp and Donut.h
Describes donut object. Constructor is Donut( double inner_radius, double outer_radius, unsigned int rot_increment ). Creates a donut like object with a inner circle of radius inner_radius and outer circle of outer_radius. Has smaller circles drawn inside of outer circle and outside of inner circle at rot_increments.

IncrementalRotate.cpp and IncrementalRotate.h
Describes incremented rotated shape object. (You have to see it!!). Constructor is IncrementalRotate( unsigned int rotation_increment, obj_ptr mod_obj). Creates several of the mod_obj (other PageObject) all rotated by the rotation_increment. Rotation is done about the lower left corner of the bounding box on the mod_obj. (play with it!)

InvisibleBox.cpp and InvisibleBox.h
Describes invisible box object. Constructor is InvisibleBox( double width, double height). Creates a rectangle of passed height and width that is not drawn to create empty space.  

WarpedCircle.cpp and WarpedCircle.h
Describes warped circle object. Constructor is WarpedCircle(double radius, double direction, double distance). Creates a warped circle of radius with tail, rotated about the tails tip by direction (angle). From center of circle to tip of tail is described by distance. "It blows your mind!" -Creator

ColoredPageObject.cpp and ColoredPageObject.h
Describes colored object. Constructor is ColoredPageObject(double red, double green, double blue, obj_ptr). Where red, blue and green are rob values between o and 1. Also, where obj_ptr is a shared_ptr at some other object inheriting from PageObject. 

ScaledPageObject.cpp and ScaledPageObject.h
Describes scalded object. Constructor is ScaledPageObject(double xScale, double yScale, obj_ptr). Where obj_ptr points to some other PageObject. xScale multiplies passed obj's width and yScale multiplies obj's height.  

RotPageObject.cpp and RotPageObject.h 
Describes rotated object. Constructor is RotPageObject(double rotation_angle, obj_ptr). Where obj_ptr points to some other PageObject. Object is rotated about the center by rotation_angle. 

OverlappedPagedObject.cpp and OverlappedPageObject.h
Describes Overlapping objects. Constructor is OverlappedPageObject(obj_ptr, obj_ptr). Where both obj_ptr point to some other PageObject. Object places object onto of each other. 

PairPageObject.cpp and PairPageObject.h
Describes pair objects (objects horizontally listed). Constructor is PairPageObject(obj_ptr left, obj_ptr right). Where both obj_ptr point to some other PageObject. Object places left object to the left of the center and right object to the right object of the center. 

StackedPageObject.cpp and StackedPageObject.h
Describes stacked objects (objects vertically listed). Constructor is StackedPageObject(obj_ptr top, obj_ptr bottom). Where both obj_ptr point to some other PageObject. Object places top object above center and bottom object bellow center. 

How to
===
Note that objects come in three relative groupings: primitives (shapes), effects (color, scale, rotation), and groupings (pair, stacked, overlapping). (Special case: IncrementalRotate is somewhat like a shape and grouping at the same time). 

Note2: To use a specific PageObject you must include the header file of that object. 

To draw a basic shape:
Create primitive <PageObject> with constructor call. Call <PageObject>.draw(ostr,x,y). This will "draw" (pass PostScript code to the ostr ostream) the primitive shape object with center at (x,y) in postScript increments. 

Circle myCirlce( 32 ); //creates circle with radius 32 PostScript Unites (72 = 1 inch)
myCircle(cout, 0,0); //Will print out PostScript to console for circle drawn at (0,0)

To draw a colored circle:
Create a obj_ptr (shared_ptr) of a Circle. Pass the circle to the color object page object constructor. Draw as above. 

obj_ptr myCirclePtr = make_shared<Circle>( 32 ); //Creates a shared ptr to a circle of radius 32
ColoredPageObject myColoredObject(1,0,0, myCirclePtr); // Creates a red circle object

myColoredObject.draw(cout, 0, 0); // Prints PostScript code for red circle at origin with radius 32. 






