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

using std::unique_ptr; using std::make_unique;
using std::vector;

int main() 
{
	vector<unique_ptr<Shape>> shapes;

	unique_ptr<Shape> shape = make_unique<Circle>();
	shapes.push_back(std::move(shape));//shape is not pointing to valid data

	shape = make_unique<Line>();//create new heap data
	shapes.push_back(std::move(shape));//shape is not pointing to valid data

	for(auto& shape: shapes)	
	{
		shape->draw();
	}

	return 0;
}