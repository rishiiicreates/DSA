//flow: representation -> identification -> which heap to choose -> code variation
//stack like structure but in reality a fully filled binary tree from left to right.

//identifcation:
// mainly sorting type of questions.
// 1) k
// 2) smallest/largest


//there are two types of heap:
//a)min heap
//b)max heap


//Heap to choose:
// k + largest: min heap
// k + smallest: max heap



//ex: arr[] = {7, 10, 4, 3, 20, 15}, k = 3 -> smallest;

//sorting to k; n(logn) -> n(logk)

//stack will fill up like this:
//7
//7-10
//4-7-10
//3-4-7-10 (size more that k, pop())
//3-4-7-20 -> pop()
//3-4-7-15 -> pop()

//stack.top() = answer;


//try using stl - heap:

//max heap -> priority_queue<int> maxheap; {largest, greatest, top}
//min heap -> priority_queue<int, vector<int>, greater<int>> minheap; {smallest, lowest}



/*
 * Explanation:
 * This file serves as an introductory guide for Heap data structures in C++ and problem-solving.
 * It explains that heaps (priority queues) are essentially fully-filled binary trees represented as stack-like structures.
 * It outlines how to identify heap-related problems, generally focusing on finding 'k' largest or smallest elements.
 * For "k smallest" elements, it recommends using a max-heap. For "k largest" elements, a min-heap is used.
 * It provides a trace of inserting elements into a heap with a size constraint, dropping elements that exceed the bound to maintain the 'k' limit.
 * Finally, it provides the standard C++ STL syntax for initializing a max-heap and a min-heap.
 */
