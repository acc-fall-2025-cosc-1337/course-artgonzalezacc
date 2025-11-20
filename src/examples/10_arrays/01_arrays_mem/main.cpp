#include "arrays_mem.h"

int main() 
{
	const int SIZE = 3;
    int nums[SIZE]{6, 1, 10};
	
	display_array_via_pointer(nums, SIZE);

	return 0;

}