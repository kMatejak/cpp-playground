#include <iostream>

using namespace std;


class MyClass {
    // private:
    //     static int s_data;
    //     std::string m_dt;
    public:
        static int s_data;
        std::string m_dt;
        explicit MyClass(std::string s) : m_dt(s) {}
        static void increment() {s_data++;}
        static int getNumber() {return s_data;}
        std::string getName() const {return m_dt;}
};

int main() {
    int MyClass::s_data = 0;
    MyClass text("hanlo");
    std::cout << text.getName();
    text.increment();
    std::cout << MyClass::getNumber();
    std::string myStr = "hey";
    // MyClass convert = myStr; // ERROR!
}