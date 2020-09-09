/*

CONTAINERS

TASK 1 - VECTOR:

	Ask user for vector size.
	Create methods which will return std::vector<int>.

	The method takes "int n" - elements number.
	The method should reserve space for needed elements.
	Elements inside of vector are sum of positive numbers eg.

	V[0] should be equal to 0
	V[1] should be equal to 1
	V[2] should be equal to 3
	V[3] should be equal to 6
	V[4] should be equal to 10

TASK 2 - LIST:

	Create two empty lists.
	One of lists will use push_back, the second one will use push_front.
	Using 'for' loop and given methods add numbers {0, 10, â€¦ , 90, 100} to lists.
	Display both lists.
	Sort lists with ascending order.
	Merge two lists.
	Display results
	
TASK 3 - MAP:

	Add the students an theirs savings to the map:
	Tommy â€“ 10.99
	Josh â€“ 11.77
	John â€“ 25.00
	Jane â€“ 102.00
	Create method which sums savings of students by the first letter of the name
	Display result
	
TASK 4 - PRIORITY_QUEUE:

	fill implementation where TODO is present
	expected output is 
	3
	4
	7
	
	#include <iostream>
	#include <queue>
	
	class TaskQueue
	{
	public:
		TaskQueue(){}
		bool empty()
		{
			return numbers.empty();
		}
		void addTask(int val)
		{
			numbers.push(val);
		}
		int getNext()
		{
			// TODO: fill method to return top value and remove it from queue
			numbers.pop();
		}
		std::priority_queue<int // TODO: use additional parameters to override default order  > numbers;
	};

	int main()
	{
		TaskQueue t;
		t.addTask(7);
		t.addTask(3);
		t.addTask(4);
		while (! t.empty())
		{
			std::cout << t.getNext() << std::endl;
		}
	}
	
*/