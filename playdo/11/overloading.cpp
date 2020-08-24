#include <iostream>
#include <string>

using namespace std;


void print(int i)
{
    std::cout << " hi int: ";
    std::cout << i;
    std::cout << std::endl;
}

void print(double f)
{
    std::cout << " hi float: ";
    std::cout << f;
    std::cout << std::endl;
}

void print(std::string c)
{
    std::cout << " hi text: " << c;
    std::cout << std::endl;
}

int main()
{
    print(10);
    print(10.10);
    print("ten");
}
