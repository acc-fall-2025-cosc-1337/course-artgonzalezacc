#include<iostream>

using std::cout;

template<class T>
T add(T a, T b)
{
	return a + b;
}

int main() 
{
	auto result = add(5, 5);
	cout<<result<<"\n";

	auto result1 = add(5.5, 5.7);
	cout<<result1<<"\n";

	return 0;
}