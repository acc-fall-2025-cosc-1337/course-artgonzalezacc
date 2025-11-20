#include "dynamic_memory.h"

using std::cout;

int main() 
{
	//create memory
	int* nums = get_dynamic_memory(3);

	//use memory How long will this data be needed????
	nums[0] = 6;
	nums[1] = 1;
	nums[2] = 10;

	for(auto i =0; i < 3; i++)
	{
		cout<<nums[i]<<"\n";
	}

	delete_dynamic_memory(nums);

	nums = nullptr;
	
	return 0;
}