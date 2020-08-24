# Lecture zero Nokia Academy C++
  
## __[sld.03]__ Types in C++, Type classification
  
## Typy fundamentalne
  
_<https://pl.cppreference.com/w/cpp/language/types>_  
_<https://docs.microsoft.com/pl-pl/cpp/cpp/fundamental-types-cpp?view=vs-2019>_  
  
### Typ void  
  
- __void__  
Typ z pustym zbiorem możliwych wartości. Jest to niepełny typ, który nie może być skompletowany (w związku z czym obiekty typu void nie są dozwolone). Nie istnieją tablice elementów typu void, ani referencje na void. Jednakże wskaźniki na void i funkcje zwracające void (procedury w innych językach) są dozwolone.  
- [__std::nullptr_t__](https://pl.cppreference.com/w/cpp/types/nullptr_t)  
std::nullptr_t to typ literału pustego wskaźnika, nullptr. Jest osobnym typem, który sam w sobie nie jest typem wskaźnika ani wskaźnika do składowej.  
  
### Typ boolowski  
  
- __bool__  
Typ, mogący przechowywać jedną z dwóch wartości: true (prawdę) lub false (fałsz). Wartość wyrażenia sizeof(bool) jest zależna od implementacji i może się różnić od 1.  
  
### Typy znaków
  
- __signed char__  
Typ reprezentujący znak, mogący przyjmować wartość ujemną.
- __unsigned char__  
Typ reprezentujący znak, mogący przyjąć tylko wartość **nie**ujemną. Jest również używany do sprawdzania reprezentacji obiektu (surowej pamięci, znajdującej się pod danym adresem).  
- __char__  
Typ reprezentacji znaku, który może być przetwarzany z największą wydajnością na docelowym systemie (ma tą samą reprezentację i wyrównanie pamięci co signed char lub unsigned char, ale jest zawsze oddzielnym typem). Wielobajtowe ciągi znaków używają tego typu, do reprezentacji jednostki kodu. Typy znakowe są wystarczająco duże, by móc reprezentować dowolną jednostkę kodowania UTF-8 (od C++14). Możliwość przechowywania wartości ujemnych przez char zależy od kompilatora oraz od platformy docelowej: domyślnie dla ARM oraz PowerPC są zwykle bez znaku, dla x86 i x64 są zwykle ze znakiem.  
  
### Typy całkowite
  
- __int__  
Bazowy typ dla liczb całkowitych. Słowo kluczowe int może być pominięte jeśli którykolwiek z wymienionych poniżej modyfikatorów został użyty. Jeśli nie został użyty żaden modyfikator długości, przyjmowana jest długość przynajmniej 16 bitów. Jednakże na 32/64-bitowych systemach operacyjnych jest to prawie zawsze pewne, że będzie miał przynajmniej 32 bity (zobacz poniżej).  
  
__Modyfikatory typów całkowitych__  
Modyfikują typ całkowity. Mogą być użyte w dowolnej kolejności. Tylko jeden typ z każdej grupy może zostać użyty.  

- Możliwość przechowywania wartości ze znakiem  
  - __signed__  
  Typ docelowy będzie posiadał możliwość przechowywania wartości ujemnych - tzw. reprezentacja ze znakiem (domyślne, jeśli zostało pominięte).  
  - __unsigned__  
  Typ docelowy nie będzie mógł przyjmować wartości ujemnych - reprezentacja bez znaku.
- Rozmiar  
  - __short__  
  Typ docelowy będzie zoptymalizowany pod względem wielkości i będzie miał długość przynajmniej 16 bitów.  
  - __long__  
  Typ docelowy będzie miał długość przynajmniej 32 bitów.  
  - __long long__  
  Typ docelowy będzie miał długość przynajmniej 64 bitów (od C++11).  
Notka: tak jak przy każdym specyfikatorze typu, kolejność modyfikatorów jest dowolna: `unsigned long long int` oraz `long int unsigned long` są tym samym typem.  
  
__Właściwości__  
[Link do tabeli zawierającej wszystkie dostępne typy całkowite oraz ich właściwości](https://pl.cppreference.com/w/cpp/language/types#W.C5.82a.C5.9Bciwo.C5.9Bci)  
  
Oprócz minimalnej ilości bitów, standard C++ gwarantuje, że:  
  
```cpp
1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
```
  
_Notka_: Istnieje ekstremalna sytuacja, w której bajty mają rozmiar 64 bitów, wtedy wszystkie typy (włącznie z char) mają 64 bity, oraz sizeof zwraca 1 dla każdego typu.  
_Notka_: arytmetyka na liczbach całkowitych jest zdefiniowana osobno dla typów ze znakiem oraz bez znaku.  
  
### Typy zmiennoprzecinkowe  
  
- __float__  
Typ zmiennoprzecinkowy pojedynczej precyzji. Zwykle oparty na standardzie IEEE-754 32 bit.  
- __double__  
Typ zmiennoprzecinkowy podwójnej precyzji. Zwykle oparty na standardzie IEEE-754 64 bit.  
- __long double__  
Typ zmiennoprzecinkowy o rozszerzonej precyzji. Nie musi koniecznie kierować się typami nałożonymi przez IEEE-754. Zwykle 80-bitowy x87 zmiennoprzecinkowy typ na architekturach x86 oraz x86-64.  
  
__Właściwości__  
Liczby zmiennoprzecinkowe mogą być użyte z operatorami arytmetycznymi `+ - / *` oraz różnymi funkcjami matematycznymi z `cmath`. Wbudowane operatory, tak samo jak funkcje z biblioteki mogą rzucić wyjątki liczb zmiennoprzecinkowych oraz ustawić `errno` w sposób opisany w `math_errhandling`.  
  
Niektóre operacje na liczbach zmiennoprzecinkowych podlegają wpływom stanu środowiska liczb zmiennoprzecinkowych (najbardziej zauważalnie, przy kierunku zaokrąglania).  
  
Niejawne konwersje są zdefiniowane pomiędzy zmiennoprzecinkowymi typami rzeczywistymi oraz typami całkowitymi.  
  
__Zakresy wartości__  
[Tabela przedstawiająca wartości referencyjne limitów popularnych reprezentacji typów numerycznych](https://pl.cppreference.com/w/cpp/language/types#Zakresy_warto.C5.9Bci)
  
```cpp
int result = 0;        // Deklaracja i inicjalizacja l. całkowitej
double coef = 10.8;    // Deklaracja i inicjalizacja l. zmiennoprzecinkowej
auto name = "Lady G."; // Deklaracja zmiennej i danie kompilatorowi wydedukować jakiego typu jest zmienna
auto adress;           // Błąd. Kompilator nie może wydedukować typu bez zainicjalizowania wartości zmiennej
age = 12;              // Błąd. Zmienna musi być zadeklarowana z typem lub przez słowo kluczowe `auto`
result = "Kenny G."    // Błąd. Tekst nie może być przypisany do zmiennej typu int.
string result = "zero";// Błąd. Nie można zmienić typu istniejącej zmiennej.
int maxValue;          // Niezalecane! maxValue zawiera śmieciowe bity aż nie zostanie zainicjalizowane
```
  
## Typy złożone  
  
<https://en.cppreference.com/w/cpp/language/type>  
  
### [__Referencja__](https://en.cppreference.com/w/cpp/language/reference)  
  
```cpp
int& a[3];  // error
int&* p;    // error
int& &r;    // error
```
  
[learncpp.com about references](https://www.learncpp.com/cpp-tutorial/611-references/)  
C++ supports three kinds of references:
  
- References to non-const values (typically just called “references”, or “non-const references”), which we’ll discuss in this lesson.  
- References to const values (often called “const references”), which we’ll discuss in the next lesson.  
- C++11 added r-value references, which we cover in detail in the chapter on move semantics.  
  
### References to non-const values  
  
A reference (to a non-const value) is declared by using an ampersand (&) between the reference type and the variable name:
  
```cpp
int value{ 5 }; // normal integer
int &ref{ value }; // reference to variable value
```
  
In this context, the ampersand does not mean “address of”, it means “reference to”.  
References to non-const values are often just called “references” for short.  
Just like the position of the asterisk of pointers, it doesn’t matter if you place the ampersand at the type or at the variable name.
  
```cpp
int value{ 5 };
// These two do the same.
int& ref1{ value };
int &ref2{ value };
```
  
### References as aliases  
  
References generally act identically to the values they’re referencing. In this sense, a reference acts as an alias for the object being referenced. For example:
  
```cpp
int x{ 5 }; // normal integer
int &y{ x }; // y is a reference to x
int &z{ y }; // z is also a reference to x
```
  
In the above snippet, setting or getting the value of x, y, or z will all do the same thing (set or get the value of x).
Let’s take a look at references in use:
  
```cpp
#include <iostream>

int main() {
  int value{ 5 }; // normal integer
  int &ref{ value }; // reference to variable value
  value = 6; // value is now 6
  ref = 7; // value is now 7
  std::cout << value << '\n'; // prints 7
  ++ref;
  std::cout << value << '\n'; // prints 8
  return 0;
}
```
  
This code prints:  
7  
8  
  
In the above example, ref and value are treated synonymously.  
Using the address-of operator on a reference returns the address of the value being referenced:
  
```cpp
cout << &value; // prints 0012FF7C
cout << &ref; // prints 0012FF7C
```
  
Just as you would expect if ref is acting as an alias for the value.
  
### l-values and r-values  
  
In C++, variables are a type of l-value (pronounced ell-value). An l-value is a value that has an address (in memory). Since all variables have addresses, all variables are l-values. The name l-value came about because l-values are the only values that can be on the left side of an assignment statement. When we do an assignment, the left hand side of the assignment operator must be an l-value. Consequently, a statement like 5 = 6; will cause a compile error, because 5 is not an l-value. The value of 5 has no memory, and thus nothing can be assigned to it. 5 means 5, and its value can not be reassigned. When an l-value has a value assigned to it, the current value at that memory address is overwritten.  
  
The opposite of l-values are r-values (pronounced arr-values). An r-value is an expression that is not an l-value. Examples of r-values are literals (such as 5, which evaluates to 5) and non-l-value expressions (such as 2 + x).  
  
Here is an example of some assignment statements, showing how the r-values evaluate:
  
```cpp
int y;      // define y as an integer variable
y = 4;      // 4 evaluates to 4, which is then assigned to y
y = 2 + 5;  // 2 + 5 evaluates to 7, which is then assigned to y

int x;      // define x as an integer variable
x = y;      // y evaluates to 7 (from before), which is then assigned to x.
x = x;      // x evaluates to 7, which is then assigned to x (useless!)
x = x + 1;  // x + 1 evaluates to 8, which is then assigned to x.
```
  
Let’s take a closer look at the last assignment statement above, since it causes the most confusion.  

```cpp
x = x + 1;
```
  
In this statement, the variable `x` is being used in two different contexts. On the left side of the assignment operator, “x” is being used as an l-value (variable with an address). On the right side of the assignment operator, x is being used as an r-value, and will be evaluated to produce a value (in this case, 7). When C++ evaluates the above statement, it evaluates as:  
  
```cpp
x = 7 + 1;
```
  
Which makes it obvious that C++ will assign the value 8 back into variable x.  
  
The key takeaway is that on the left side of the assignment, you must have something that represents a memory address (such as a variable). Everything on the right side of the assignment will be evaluated to produce a value.  
  
Note: const variables are considered non-modifiable l-values.  
  
### References must be initialized  
  
References must be initialized when created:

```cpp
int value{ 5 };
int &ref{ value }; // valid reference, initialized to variable value

int &invalidRef; // invalid, needs to reference something
```
  
Unlike pointers, which can hold a null value, there is no such thing as a null reference.  
References to non-const values can only be initialized with non-const l-values. They can not be initialized with const l-values or r-values.  
  
```cpp
int x{ 5 };
int &ref1{ x }; // okay, x is an non-const l-value

const int y{ 7 };
int &ref2{ y }; // not okay, y is a const l-value

int &ref3{ 6 }; // not okay, 6 is an r-value
```
  
Note that in the middle case, you can’t initialize a non-const reference with a const object -- otherwise you’d be able to change the value of the const object through the reference, which would violate the const-ness of the object.  
  
### References can not be reassigned  
  
Once initialized, a reference can not be changed to reference another variable. Consider the following snippet:  
  
```cpp
int value1{ 5 };
int value2{ 6 };

int &ref{ value1 }; // okay, ref is now an alias for value1
ref = value2; // assigns 6 (the value of value2) to value1 -- does NOT change the reference!
```
  
Note that the second statement may not do what you might expect! Instead of changing ref to reference variable value2, it assigns the value of value2 to value1.  
  
### [Lvalue references](https://en.cppreference.com/w/cpp/language/reference)    
  
Lvalue references can be used to alias an existing object (optionally with different cv-qualification):
  
```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Ex";
    std::string& r1 = s;
    const std::string& r2 = s;

    r1 += "ample";           // modifies s
//  r2 += "!";               // error: cannot modify through reference to const
    std::cout << r2 << '\n'; // prints s, which now holds "Example"
}
```
  
They can also be used to implement pass-by-reference semantics in function calls:
  
```cpp
#include <iostream>
#include <string>

void double_string(std::string& s) {
    s += s; // 's' is the same object as main()'s 'str'
}

int main() {
    std::string str = "Test";
    double_string(str);
    std::cout << str << '\n';
}
```
  
When a function's return type is lvalue reference, the function call expression becomes an lvalue expression:
  
```cpp
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
```
  
### Dangling references  
  
Although references, once initialized, always refer to valid objects or functions, it is possible to create a program where the lifetime of the referred-to object ends, but the reference remains accessible (dangling). Accessing such a reference is undefined behavior. A common example is a function returning a reference to an automatic variable:  
  
```cpp
std::string& f()
{
    std::string s = "Example";
    return s; // exits the scope of s:
              // its destructor is called and its storage deallocated
}
  
std::string& r = f(); // dangling reference
std::cout << r;       // undefined behavior: reads from a dangling reference
std::string s = f();  // undefined behavior: copy-initializes from a dangling reference
```
  
### __Wskaźnik__  
  
- [link 1 \(ang)](https://en.cppreference.com/w/cpp/language/pointer)
- [link 2 \(pl)](https://pl.wikibooks.org/wiki/C/Wska%C5%BAniki)  
  
Every value of pointer type is one of the following:
  
- a _pointer to an object or function_ (in which case the pointer is said to _point_ to the object or function), or  
- a _pointer past the end of an object_, or  
- the _null pointer value_ for that type, or  
- an _invalid pointer value_.  
  
A pointer that points to an object _represents the address_ of the first byte in memory occupied by the object. A pointer past the end of an object _represents the address_ of the first byte in memory after the end of the storage occupied by the object.  
  
Note that two pointers that represent the same address may nonetheless have different values.  
  
```cpp
struct C {
  int x, y;
} c;

int* px = &c.x;    // value of px is "pointer to c.x"
int* pxe = px + 1; // value of pxe is "pointer past the end of c.x"
int* py = &c.y;    // value of py is "pointer to c.y"

assert(pxe == py); // == tests if two pointers represent the same
                   // address may or may not fire

*pxe = 1; // undefined behavior even if the assertion does not fire
```
  
Indirection through an invalid pointer value and passing an invalid pointer value to a deallocation function have undefined behavior. Any other use of an invalid pointer value has implementation-defined behavior.  
  
__Pointers to objects__
A pointer to object can be initialized with the return value of the address-of operator applied to any expression of object type, including another pointer type:  
  
```cpp
int n;
int* np = &n;           // pointer to int
int* conts* npp = &np;  // non-const pointer to const pointer to non-const int

int a[2];
int (*ap)[2] = &a;   // pointer to array of int

struct S { int n; };
S s = {1};
int* sp = &s.n;      // pointer to the int that is a member of s
```
  
### [__Array__](https://en.cppreference.com/w/cpp/language/array)
  
A declaration of the form T a[N];, declares a as an array object that consists of N contiguously allocated objects of type T. The elements of an array are numbered 0, …, N - 1, and may be accessed with the subscript operator [], as in a[0], …, a[N - 1].  
  
Arrays can be constructed from any fundamental type (except `void`), pointers, pointers to members, classes, enumerations, or from other arrays of known bound (in which case the array is said to be multi-dimensional). In other words, only object types except for array types of unknown bound can be element types of array types. Array types of incomplete element type are also incomplete types.  
  
### [__Enum__](https://en.cppreference.com/w/cpp/language/enum)  
  
An enumeration is a distinct type whose value is restricted to a range of values, which may include several explicitly named constants ("enumerators"). The values of the constants are values of an integral type known as the underlying type of the enumeration.  
  
__There are two distinct kinds of enumerations: unscoped enumeration (declared with the enum-key enum) and scoped enumeration (declared with the enum-key enum class or enum struct).__  
  
[__Unscoped enumeration__](https://en.cppreference.com/w/cpp/language/enum#Unscoped_enumeration)  
Each _enumerator_ becomes a named constant of the enumeration's type (that is, _name_), visible in the enclosing scope, and can be used whenever constants are required.  
  
```cpp
enum Color { red, green, blue };
Color r = red;
switch(r) {
  case red   : std::cout << "red\n";   break;
  case green : std::cout << "green\n"; break;
  case blue  : std::cout << "blue\n";  break;
}
```
  
Each enumerator is associated with a value of the underlying type. When initializers are provided in the enumerator-list, the values of enumerators are defined by those initializers. If the first enumerator does not have an initializer, the associated value is zero. For any other enumerator whose definition does not have an initializer, the associated value is the value of the previous enumerator plus one.  
  
```cpp
enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };
// a = 0, b = 1, c = 10, d = 11, e = 1, f = 2, g = 12
```
  
Values of unscoped enumeration type are implicitly-convertible to integral types. If the underlying type is not fixed, the value is convertible to the first type from the following list able to hold their entire value range: `int`, `unsigned int`, `long`, `unsigned long`, `long long`, or `unsigned long long`. If the underlying type is fixed, the values can be converted to their promoted underlying type.  
  
```cpp
enum color { red, yellow, green = 20, blue };
color col = red;
int n = blue;    // n == 21
```
  
When an unscoped enumeration is a class member, its enumerators may be accessed using class member access operators . and ->:
  
```cpp
struct X
{
    enum direction { left = 'l', right = 'r' };
};
X x;
X* p = &x;

int a = X::direction::left; // allowed only in C++11 and later
int b = X::left;
int c = x.left;
int d = p->left;
```
  
[__Scoped enumerations__](https://en.cppreference.com/w/cpp/language/enum#Scoped_enumerations)  
  
```cpp
enum class Color { red, green = 20, blue };
Color r = Color::blue;
switch(r) {
  case Color::red   : std::cout << "red\n";   break;
  case Color::green : std::cout << "green\n"; break;
  case Color::blue  : std::cout << "blue\n";  break;
}
// int n = r;  // error; no scoped enum to int conversion
int n = static_cast<int>(r);  // OK, n == 21
```
  
### [Klasa](https://en.cppreference.com/w/cpp/language/class)  
  
[__Member specification__](https://en.cppreference.com/w/cpp/language/class#Member_specification)  

1. Member declarations of the form  
This declaration may declare static and non-static data members and member functions, member typedefs, member enumerations, and nested classes. It may also be a friend declaration.  

```cpp
class S {
  int d1; // non-static data member
  int a[10] = {1,2}; // non-static data member with initializer (C++11)
  static const int d2 = 1;  // static data member with initializer
  virtual void f1(int) = 0; // pure virtual member function
  std::string d3, *d4, f2(int); // two data members and a member function
  enum {NORTH, SOUTH, EAST, WEST};
  struct NestedS {
    std::string s;
  } d5, *d6;
  typedef NestefdS value_type, *pointer_type;
};
```

2. Function definitions, which both declare and define member functions or friend functions. A semicolon after a member function definition is optional. All functions that are defined inside a class body are automaticaly inline.  

```cpp
class M {
    std::size_t C;
    std::vector<int> data;
 public:
    M(std::size_t R, std::size_t C) : C(C), data(R*C) {} // constructor definition 
    int operator()(size_t r, size_t c) const { // member function definition
        return data[r*C+c];
    }
    int& operator()(size_t r, size_t c) {  // another member function definition
        return data[r*C+c];
    }
};
```

3. Access specifiers public:, protected:, and private:

```cpp
class S {
 public:
    S();          // public constructor
    S(const S&);  // public copy constructor
    virtual ~S(); // public virtual destructor
 private:
    int* ptr; // private data member
};
```

4. [Using-declarations](https://en.cppreference.com/w/cpp/language/using_declaration)  

```cpp
class Base {
 protected:
     int d;
};
class Derived : public Base {
 public:
    using Base::d; // make Base's protected member d a public member of Derived
    using Base::Base; // inherit all parent's constructors (C++11)
};
```
  
\[...]  
Aaaand so go on, to __nine__, but I don't know why... 
  
## __[sld.04]__ Types in C++, Initialization and `auto` keyword  

```cpp
int number(2);
bool isMine = number;    // isMine == true

float height = 2.45;
int newHeight = height;  // newHeight == 2

int x;    // ok, x == ?
int x{};  // ok, x == 0

auto x1 = 27;    // x1 is int
auto x2(27);     // x2 is int
auto x3 = {27};  // x3 is std::initializer_list<int>
auto x4{27};     // x4 is std::initializer_list<int>
```

[my playin' around snipet above](../playdo/04/auto.cpp)  
  
## __[sld.05]__ Types in C++, Pointers and references  

```cpp
int i = 3;     // our variable
int *ptr = &i  // pointer with type int*
int &ref = i;  // reference with type int&

std::cout << ptr   // print address
std::cout << *ptr  // print value

int &ref2 = 7;        // cannot be initialized
const int& ref3 = 10; // can be initialized
```

And snippet from https://stackoverflow.com/a/4629355/12474392  
> There are a number of answers saying things along the lines of "references are just syntactic sugar for easier handling of pointers". They most certainly are not.  
> Consider the following code:  

```cpp
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
```

The line `p = pointerToB` changes the value of `p`, i.e. it now points to a different piece of memory.  
  
`r = referenceToB` does something completely different: it assigns the value of `b` to where the value of `a` used to be. It does __not__ change `r` at all. `r` is still a reference to the same piece of memory.  
  
The difference is subtle but very important.  
  
[my playin' around snipets above](../playdo/05/pointers_and_refrs.cpp)  
