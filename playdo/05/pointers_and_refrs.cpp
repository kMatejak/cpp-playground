#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    int i = 3;      // our variable
    int *ptr = &i;  // pointer with type int*
    int &ref = i;   // reference with type int&
    string ptr_type = typeid(ptr).name();
    string ref_type = typeid(&ref).name();
    system(("echo " + ptr_type + " | c++filt -t").c_str());
    system(("echo " + ref_type + " | c++filt -t").c_str());
    std::cout << "\n";

    std::cout << ptr << "\n";   // print address
    std::cout << *ptr << "\n";  // print value
    std::cout << "\n";

//  int &ref2 = 7;        // cannot be initialized
    const int& ref3 = 10; // can be initialized
    std::cout << ref3 << "\n";
    std::cout << "\n";

// - - - - - - - - - - - - - 

    int a = 3;
    int b = 4;
    int* pointerToA = &a;
    int* pointerToB = &b;
    int* p = pointerToA;
    p = pointerToB;
    printf("%d %d %d\n", a, b, *p); // Prints 3 4 4
    int& referenceToA = a;
    int& referenceToB = b;
    int& r = referenceToA;
    r = referenceToB;
    printf("%d %d %d\n", a, b, r); // Prints 4 4 4
    std::cout << "\n";
}