// When a function's return type is lvalue reference, 
// the function call expression becomes an lvalue expression
#include <iostream>
#include <string>

char& char_number(std::string& s, std::size_t n) {
    return s.at(n); // string::at() returns a reference to char
}

int main() {
    std::string str = "Test";
    char_number(str, 1) = 'a'; // the function call is lvalue, can be assigned to
    std::cout << str << '\n';
}