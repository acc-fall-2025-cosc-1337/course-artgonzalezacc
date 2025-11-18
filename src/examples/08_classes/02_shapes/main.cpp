//main
#include <iostream>
#include<memory>
#include<vector>
#include "shape.h"
#include "line.h"
#include "circle.h"
/*
Create a Shape pointer of type Line
Create vector of Shape pointers
iterate with auto
*/

int main() 
{
	Shape* shape;//pointer
	shape = new Circle();//create dynamic memory on the heap
	shape->draw();

	delete shape;

	shape = new Line();
	shape->draw();

	delete shape;
	return 0;
}