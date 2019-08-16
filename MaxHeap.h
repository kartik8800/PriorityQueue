///author : Kartik Arora

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<vector>

template<class T>
class MaxHeap
{
    public:
        /*
         *constructs an empty Max heap
         *this max heap will hold objects of type T
         *the priority of the objects will be decided
         *by a user defined function.
        */
        MaxHeap<T> (bool (*comp)(T obj1, T obj2));
        //return true if the Max Heap is empty, true otherwise.
        bool isEmpty();
        //used to insert an item in the priority queue.
        void push(T obj);
        //deletes the highest priority item currently in the queue.
        void pop();
        //return the highest priority item currently in the queue.
        T top();
    private:
        //return true if obj1 compares less than obj2
        bool (*compare)(T obj1, T obj2);
        //the max heap is implemented using a vector.
        std::vector<T> heap;
        void heapifyUp(int idx);
        void heapifyDown(int idx);
        int leftChild(int i)
        {
            return 2*i + 1;
        }
        int rightChild(int i)
        {
            return 2*i + 2;
        }
        int parent(int i)
        {
            return (i-1)/2;
        }
};
template<class T> MaxHeap<T>::MaxHeap(bool (*comp)(T obj1, T obj2))
{
    this -> compare = comp;
}

template<class T> bool MaxHeap<T>::isEmpty()
{
    return heap.empty();
}

template<class T> void MaxHeap<T>::push(T obj)
{
    heap.push_back(obj);
    heapifyUp(heap.size()-1);
}

template<class T> void MaxHeap<T>::pop()
{
    if(!isEmpty())
    {
       std::swap(heap[0], heap[heap.size()-1]);
       heap.pop_back();
       if(!isEmpty())
          heapifyDown(0);
    }
}

template<class T> T MaxHeap<T>::top()
{
    if(!isEmpty())
    {
       return heap[0];
    }
}

template<class T> void MaxHeap<T>::heapifyDown(int idx)
{
    int largeIdx = idx;
    int leftChildIdx = leftChild(idx), rightChildIdx = rightChild(idx);
    if(leftChildIdx < heap.size())
    {
       if(compare(heap[largeIdx], heap[leftChildIdx]))
            largeIdx = leftChildIdx;
    }
    if(rightChildIdx < heap.size())
    {
       if(compare(heap[largeIdx], heap[rightChildIdx]))
            largeIdx = rightChildIdx;
    }

    if(largeIdx != idx)
    {
       std::swap(heap[largeIdx], heap[idx]);
       heapifyDown(largeIdx);
    }
}

template<class T> void MaxHeap<T>::heapifyUp(int idx)
{
    int parentIdx = parent(idx);
    if(parentIdx < 0)
            return;
    if(compare(heap[parentIdx], heap[idx]))
    {
        std::swap(heap[parentIdx], heap[idx]);
        heapifyUp(parentIdx);
    }
}

#endif // MAXHEAP_H
