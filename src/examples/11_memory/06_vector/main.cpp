//
#include "my_vector.h"

using std::cout;

int main()
{
    MyVector<int> vector(3);
    vector.PushBack(5);
    cout<<vector[0]<<"\n";

    return 0;
}

