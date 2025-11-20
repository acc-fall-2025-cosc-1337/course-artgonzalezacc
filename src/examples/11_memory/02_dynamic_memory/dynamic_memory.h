//Create allocate and release function
#include<iostream>
#include<memory>

void use_dynamic_memory_array(const int SIZE);
int* get_dynamic_memory(const int SIZE);
void delete_dynamic_memory(int* array);
void use_dynamic_memory_shared_ptr(const int SIZE);