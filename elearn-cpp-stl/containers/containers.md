# Containers
  
## Containers::sequence  
  
Sequence containers available in STL:  
  
- std::vector  
- std::array  
- std::list  
- std::forward_list  
- std::deque  
  
### Containers::sequence::vector  
  
- Array with a dynamic size, which is cache friendly.  
- In case of being full, it allocates bigger chunk of memory.  
- During reallocation, it reserves more memory than is needed.  
  
```cpp
template <class T, class Allocator = std::allocator<T>>
class vector;

// eg.
std::vector<int> integers;
std::vector<double> rationals;
std::vector<std::string> surnames;
```
  
How to access elements:  
  
- at / operator[]
- front / back
- data
Using iterators:
- begin / cbegin
- end / cend
- rbegin / crbegin
- rend / crend
  
std::vector::iterator is a random-access iterator  
  
Public methods related to vector's capacity:  
  
- size  
- empty  
- capacity  
- reserve  
- shrink_to_fit  
- max_size  
  
### Containers::sequence::vector<bool>  
  
- `std::vector<bool>` is optimized in case of needed memory.
- To access elements it returns proxy objects.
- Additional methods: flip, swap.  
  
```cpp
std::vector<bool> v {true, false};
auto& firstElementRef = v.front();   // Compilation error!
auto firstElementProxy = v.front();  // Proxy object
```
  
### Containers::sequence::array
  
• Fixed size array, which is cache friendly.
• Zero-overhead in comparison to C-style array.
• Strong typing.
• Provides STL container interface.
  
```cpp
template <class T, std::size_t SIZE>
class array;

// e.g.
std::array<int, 10> integers;
std::array<int, 3> differentIntegers;
std::array<std::string, 9> surnames;
```
  
How to access elements:
  
- at / operator[]
- front / back
- data
  
Using iterators:
  
- begin / cbegin
- end / cend
- rbegin / crbegin
- rend / crend
  
std::array::iterator is a random-access iterator  
  
Public methods related to array's capacity:
  
• size
• empty
• max_size
  
Other methods:
  
• fill
• swap
  
In case of array we can use comparison operators.
  
### Containers::sequence::list  
  
• Doubly-linked list.
• Random access is not supported.
• Not cache friendly.
• May lead to memory fragmentation.
• Fast insert/remove operations.
  
```cpp
template <class T, class Allocator = std::allocator<T>>
class list;
// e.g.
std::list<int> integers;
std::list<std::string> surnames;
```
  
How to access elements:
  
- front / back
- Using iterators:
-- begin / cbegin
-- end / cend
-- rbegin / crbegin
-- rend / crend
  
std::list::iterator is a bidirectional iterator  
  
How to modify list:  
  
- push_back / push_front
- pop_back / pop_front
- emplace_back / emplace_front
- insert / emplace
- erase
- clear
- resize
- swap
  
Special operations of std::list:
  
- sort
- merge
- splice
- reverse
- unique
- remove / remove_if
  
### Containers::sequence::deque  
  
• Double-ended queue – often implemented as many chunks of
memory, which are allocated independently.
• In case of being full, it reallocates memory.
• Supports random access.
• Fast insert/remove operations at the beginning/end.
  
```cpp
template <class T, class Allocator = std::allocator<T>>​
class deque;​
// e.g.​
std::deque<std::string> surnames;
```
  
How to access elements:
  
- at / operator[]
- front / back
- Using iterators:
-- begin / cbegin
-- end / cend
-- rbegin / crbegin
-- rend / crend
  
std::deque::iterator is a random-access iterator  
  
Public methods related to deque's capacity:  
  
- size
- empty
- shrink_to_fit
- max_size
  
In case of deque we can use comparison operators.  
  
How to modify deque:
  
- push_back / pop_back
- push_front / pop_front
- insert / emplace
- emplace_front / emplace_back
- resize
- swap
- erase
- clear
  
## Containers::associative  
  
Associative containers available in STL:
std::map
std::multimap
std::set
std::multiset
  
### Containers::associative::map  
  
• Key-Value pairs, where key is unique.
• Elements stored inside are sorted by key.
• Usually implemented as tree.
• Complexity of search/insert/remove methods is logarithmic.
  
```cpp
template <class Key, class T, class Compare = std::less<Key>, class
Allocator = std::allocator<std::pair<const Key, T>>>​
class map;​
// e.g.​
std::map<int, std::string> students;
```
  
### Containers::associative::(multi)map
  
```cpp
std::multimap<std::string, int> grades;
const std::string studentName = “Tommy”;
grades.insert(std::make_pair(studentName, 5));
grades.insert(std::make_pair(studentName, 3));
grades.insert(std::make_pair(studentName, 4));
auto tommysGrades = grades.equal_range(studentName);
std::cout << “Tommy’s grades: “;
displayRange(tommysGrades.first, tommysGrades.second);
```
  
Output: `Tommy’s grades: 5, 3, 4`  
  
### Containers::associative::set  
  
• Contains unique values.
• Elements stored inside are sorted.
• Usually implemented as tree.
• The complexity of search/insert/remove is logarithmic.
  
## Containers::unordered_associative  
  
Unordered associative containers available in STL:  
  
- std::unordered_map
- std::unordered_multimap
- std::unordered_set
- std::unordered_multiset
  
## Containers::adaptors
  
Containers adaptors offered by STL:  
  
- std::stack
- std::queue
- std::priority_queue
  