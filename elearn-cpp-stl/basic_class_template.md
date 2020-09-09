# C++ Notes For Professionals  
  
## Section 77.1: Basic Class Template  
  
The basic idea of a class template is that the template parameter gets substituted by a type at compile time. The result is that the same class can be reused for multiple types. The user specifies which type will be used when a variable of the class is declared. Three examples of this are shown in main():  
  
```cpp
#include <iostream>
using std::cout;
template <typename T>       // A simple class to hold
                            // one number of any type
class Number {
public:
    void setNum(T n);       // Sets the class field to
                            // the given number
    T plus1() const;        // returns class field's "follower"
private:
    T num;                  // Class field
};

template <typename T>       // Set the class field to
                            // the given number
void Number<T>::setNum(T n) {
    num = n;
}

template <typename T>        // returns class field's "follower"
T Number<T>::plus1() const {
    return num + 1;
}

int main() {
    Number<int> anInt;      // Test with an integer
                            // (int replaces T in the class)
    anInt.setNum(1);

    cout << "My integer + 1 is " << anInt.plus1() << "\n";
    // Prints 2

    Number<double> aDouble;         // Test with a double
    aDouble.setNum(3.1415926535897);
    cout << "My double + 1 is " << aDouble.plus1() << "\n";
    // Prints 4.14159

    Number<float> aFloat;          // Test with a float
    aFloat.setNum(1.4);
    cout << "My float + 1 is " << aFloat.plus1() << "\n";
    // Prints 2.4

    return 0; // Successful completion
}
```  

## Section 77.2: Function Templates
  
Templating can also be applied to functions (as well as the more traditional structures) with the same effect.  
  
```cpp
// 'T' stands for the unknown type
// Both of our arguments will be of the same type.
template<typename T>
void printSum(T add1, T add2)
{
    std::cout << (add1 + add2) << std::endl;
}
```
  
This can then be used in the same way as structure templates.  
  
```cpp
printSum<int>(4, 5);
printSum<float>(4.5f, 8.9f);
```
  
In both these case the template argument is used to replace the types of the parameters; the result works just like
a normal C++ function (if the parameters don't match the template type the compiler applies the standard
conversions).  
  
One additional property of template functions (unlike template classes) is that the compiler can infer the template
parameters based on the parameters passed to the function.  
  
```cpp
printSum(4, 5);     // Both parameters are int.
                    // This allows the compiler deduce that the type
                    // T is also int.

printSum(5.0, 4);   // In this case the parameters are
                    // two different types.
                    // The compiler is unable to deduce the type of T
                    // because there are contradictions. As a result
                    // this is a compile time error.
```
  
This feature allows us to simplify code when we combine template structures and functions. There is a common pattern in the standard library that allows us to make `template structure X` using a helper function `make_X()`.  
  
```cpp
// The make_X pattern looks like this.
// 1) A template structure with 1 or more template types.
template<typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};
// 2) A make function that has a parameter type for
// each template parameter in the template structure.
template<typename T1, typename T2>
MyPair<T1, T2> make_MyPair(T1 t1, T2 t2)
{
    return MyPair<T1, T2>{t1, t2};
}
```
  
How does this help?  
  
```cpp
auto val1 = MyPair<int, float>{5, 8.7};
                // Create object explicitly defining the types

auto val2 = make_MyPair(5, 8.7);
                // Create object using the types of the parameters.
                // In this code both val1 and val2 are the same
                // type.
```
  
Note: This is not designed to shorten the code. This is designed to make the code more robust. It allows the types to be changed by changing the code in a single place rather than in multiple locations.  
  