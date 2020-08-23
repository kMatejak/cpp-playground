// Although references, once initialized, always refer to 
// valid objects or functions, it is possible to create 
// a program where the lifetime of the referred-to object ends, 
// but the reference remains accessible (dangling). 
// Accessing such a reference is undefined behavior. 
// A common example is a function returning a reference to
// an automatic variable:
#include <iostream>
#include <string>

std::string& f() {
    std::string s = "Example";
    return s; // exists the scope of s:
              // its destructor is called and its storage deallocated
}

int main() {
    std::string& r = f(); // dangling reference
    std::cout << r;       // undefined behavior: reads from a dangling reference
    std::string s = f();  // undefined behavior: copy-initializes from a dangling reference
}