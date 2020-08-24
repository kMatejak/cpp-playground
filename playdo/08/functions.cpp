#include <iostream>
#include <typeinfo>

using namespace std;


// prototype
int retInt (int r, int s = 5);

// definition
int retRet (int r = 4) 
{
    // body
    return r;
}


int main() {
    //function call
    std::cout << retRet();
    std::cout << "\n";
}
