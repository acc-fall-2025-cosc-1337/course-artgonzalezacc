#include "arrays_mem.h"

using std::cout;

int main() 
{
	int* pointer = array_return_value();
	cout<<*pointer<<"\n";

	return 0;

}