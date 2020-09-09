#include <iostream>
#include <cstddef>
#include <array>

template <class T, std::size_t SIZE>
class array;

int main () {
    std::array<int, 5> numbers;

    std::cout << std::boolalpha;
    std::cout << "Is empty: " << numbers.empty() << "\n";
    std::cout << "Size: " << numbers.size() << "\n";
    std::cout << "Max size: " << numbers.max_size() << "\n";
};