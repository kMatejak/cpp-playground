#include <iostream>

using namespace std;


int* process()
{
    int x = 5;
    return &x;
}

int main()
{
    int *p = process();
    std::cout << *p;
}


// A pointer pointing to a memory location 
// of already deleted object is known as
// dangling pointer.

// runtime error:
// [1]    18733 segmentation fault (core dumped)