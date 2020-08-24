#include <iostream>

#define SQUARE(x) x*x

int main() 
{
    int x = 5;
    std::cout << SQUARE(x);

    #undef SQUARE

    std::cout << SQUARE(x); // SQUARE was not declared!

}