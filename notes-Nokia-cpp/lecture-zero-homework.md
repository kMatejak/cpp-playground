# Lecture zero Nokia Academy C++
  
## __[sld.02]__ Types in C++, Type classification
  
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
  
- [__referencja__](https://en.cppreference.com/w/cpp/language/reference)  
  
```cpp
int& a[3];  // error
int&* p;    // error
int& &r;    // error
```
  
__Lvalue references__
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
  
__Dangling references__  
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
  
- __wskaźnik__  
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
  
- [array](https://en.cppreference.com/w/cpp/language/array)  
A declaration of the form T a[N];, declares a as an array object that consists of N contiguously allocated objects of type T. The elements of an array are numbered 0, …, N - 1, and may be accessed with the subscript operator [], as in a[0], …, a[N - 1].  
  
Arrays can be constructed from any fundamental type (except `void`), pointers, pointers to members, classes, enumerations, or from other arrays of known bound (in which case the array is said to be multi-dimensional). In other words, only object types except for array types of unknown bound can be element types of array types. Array types of incomplete element type are also incomplete types.  
  
- [enum](https://en.cppreference.com/w/cpp/language/enum)  
- [klasa](https://en.cppreference.com/w/cpp/language/class)  
  
## __[sld.03]__ Types in C++, Type classification
