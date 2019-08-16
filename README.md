# PriorityQueue
Implementation of a priority queue using a max heap.
To use the priority queue:
  1. include "MaxHeap.h" in your source file.
  2. declare a MaxHeap as "MaxHeap < myDataType > myMaxHeap(comparator)".
  3. you need to define a function comparator that accepts two objects of type myDataType and returns true if 1st compares less than 2nd        object and false otherwise.
  4. the highest priority object(does not compare less than any other object in the heap) is the topmost item in the heap.
  
The following functionalities are provided:
1. push(T obj) : inserts in the queue the item obj.
2. pop() : deletes the highest priority item from the queue.
3. top() : returns the highest priority item present in the queue.
4. isEmpty() : return 1 if there is no element in the queue. 0 otherwise.

example use:
bool comparator(int x, int y)
{
   return x < y;
}
MaxHeap < int > myMaxHeap(comparator);
myMaxHeap.push(15);
