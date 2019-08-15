# PriorityQueue
Implementation of a priority queue using a max heap.
To use the priority queue:
  1. include "MaxHeap.h" in your source file.
  2. declare a MaxHeap as "MaxHeap<myDataType> myMaxHeap(priorityRating)".
  3. you need to define a function priorityRating that accepts an object of type myDataType and returns a long long integer.
  4. the higher the value of the returned integer, higher is the priority assigned to the corresponding object.
  
The following functionalities are provided:
1. push(T obj) : inserts in the queue the item obj.
2. pop() : deletes the highest priority item from the queue.
3. top() : returns the highest priority item present in the queue.
4. isEmpty() : return 1 if there is no element in the queue. 0 otherwise.

example use:
long long priorityRating(int x)
{
   return x;
}
MaxHeap<int> myMaxHeap(priorityRating);
myMaxHeap.push(15);
