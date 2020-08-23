#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main() {
    int number(2);
    bool isMine = number;    // isMine == true
    std::cout << isMine << "\n";

    bool check = isMine == true;
    std::cout << check << "\n";
    std::cout << "------------\n";

    float height = 2.45;
    int newHeight = height;  // newHeight == 2
    std::cout << height << "\n";
    std::cout << newHeight << "\n";
    std::cout << "------------\n";

    int measure = 3;
    float decMeasure = measure;
    std::cout << measure << "\n";     // measure    == 3
    std::cout << decMeasure << "\n";  // decMeasure == 3
    std::cout << "------------\n";

    int x;          // ok, x == random value
    long long y{};  // ok, y == 0
    char ch;        // ch == random char (" ", "?", or similar)
    std::cout << x << "\n";
    std::cout << y << "\n";
    std::cout << ch << "\n";
    string my_type = typeid(y).name();
    system(("echo " + my_type + " | c++filt -t").c_str());
    // std::cout << typeid(y).name() << "\n";
    std::cout << "------------\n";

    auto x1 = 27;    // x1 is int
    auto x2(27);     // x2 is int
    auto x3 = {27};  // x3 is std::initializer_list<int>
    auto x4{27};     // x4 is std::initializer_list<int>
               // nope! x4 is int
    string x1_type = typeid(x1).name();
    string x2_type = typeid(x2).name();
    string x3_type = typeid(x3).name();
    string x4_type = typeid(x4).name();
    system(("echo " + x1_type + " | c++filt -t").c_str());
    system(("echo " + x2_type + " | c++filt -t").c_str());
    system(("echo " + x3_type + " | c++filt -t").c_str());
    system(("echo " + x4_type + " | c++filt -t").c_str());
    std::cout << "------------\n";
}