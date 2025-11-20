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
	Circle circles[3];//create an array of 3 circle items
	circles[0].draw();
	circles[1].draw();
	circles[2].draw();
	
	///////////////////////////
	Shape* shapes[3];//empty array list

	Circle circle;
	shapes[0] = &circle;
	
	Line line;
	shapes[1] = &line;
	
	Circle circle1;
	shapes[2] = &circle1;

	shapes[0]->draw();
	shapes[1]->draw();
	shapes[2]->draw();


	return 0;
}