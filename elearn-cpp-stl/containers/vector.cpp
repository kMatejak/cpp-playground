#include <iostream>
#include <cstddef>
#include <vector>

template <typename ForwardIterator>
void displayRange(ForwardIterator first, ForwardIterator last)
{
    while (first != last) {
        std::cout << *first++ << ", ";
    }
    std::cout << "\n\n";
}

int main() {
    std::vector<int> primes {2, 3, 5, 7, 11};

    displayRange(primes.rbegin(), primes.rend());

    displayRange(primes.begin(), primes.end());
}
