#include <iostream>
#include <deque>
#include <iterator>
#include <forward_list>
#include <vector>

int main() {
    std::deque<int> deque {6, 11, 12, 13, 14};
    
    std::initializer_list<int> initList {7, 8, 9, 10};
    std::copy(initList.begin(), initList.end(), std::inserter(deque, std::next(deque.begin())));
    
    std::vector<int> v {5, 4, 3, 2, 1};
    std::copy(v.begin(), v.end(), std::front_inserter(deque));
    
    std::forward_list<int> forwardList{15, 16, 17, 18};
    std::copy(forwardList.begin(), forwardList.end(), std::back_inserter(deque));
    
    std::copy(deque.begin(), deque.end(), std::ostream_iterator<int>(std::cout , " | "));
    std::cout << std::endl;
    return 0;
}