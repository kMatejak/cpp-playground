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
  
DOCZYTAĆ!
  
- [referencja](https://en.cppreference.com/w/cpp/language/reference)  
- [wskaźnik](https://en.cppreference.com/w/cpp/language/pointer)  
- [array](https://en.cppreference.com/w/cpp/language/array)
- [enum](https://en.cppreference.com/w/cpp/language/enum)  
- [klasa](https://en.cppreference.com/w/cpp/language/class)  
  
## __[sld.03]__ Types in C++, Type classification
