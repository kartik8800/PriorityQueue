///author : Kartik Arora

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<vector>

template<class T>
class MaxHeap
{
    public:
        MaxHeap<T>(long long (*priority)(T obj));
        bool isEmpty();
        void push(T obj);
        void pop();
        T top();
    private:
        long long (*priority)(T obj);
        std::vector<std::pair<int,T>> heap;
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

template<class T> MaxHeap<T>::MaxHeap(long long (*priority)(T obj))
{
    this -> priority = priority;
}

template<class T> bool MaxHeap<T>::isEmpty()
{
    return heap.empty();
}

template<class T> void MaxHeap<T>::push(T obj)
{
    heap.push_back({priority(obj),obj});
    heapifyUp(heap.size()-1);
}

template<class T> void MaxHeap<T>::pop()
{
    if(!isEmpty())
    {
       swap(heap[0], heap[heap.size()-1]);
       heap.pop_back();
       if(!isEmpty())
          heapifyDown(0);
    }
}

template<class T> T MaxHeap<T>::top()
{
    if(!isEmpty())
    {
       return heap[0].second;
    }
}

template<class T> void MaxHeap<T>::heapifyDown(int idx)
{
    long long parentVal = heap[idx].first;
    long long leftChildVal = LONG_MIN, rightChildVal = LONG_MIN;
    int leftChildIdx = leftChild(idx), rightChildIdx = rightChild(idx);
    if(leftChildIdx < heap.size())
          leftChildVal = heap[leftChildIdx].first;

    if(rightChildIdx < heap.size())
          rightChildVal = heap[rightChildIdx].first;

    long long largeVal = parentVal, largeIdx = idx;

    if(largeVal < leftChildVal)
    {
        largeVal = leftChildVal;
        largeIdx = leftChildIdx;
    }

    if(largeVal < rightChildVal)
    {
        largeVal = rightChildVal;
        largeIdx = rightChildIdx;
    }

    if(largeIdx != idx)
    {
       swap(heap[largeIdx], heap[idx]);
       heapifyDown(largeIdx);
    }
}

template<class T> void MaxHeap<T>::heapifyUp(int idx)
{
    int parentIdx = parent(idx);
    if(parentIdx < 0)
            return;
    if(heap[parentIdx].first < heap[idx].first)
    {
        swap(heap[parentIdx], heap[idx]);
        heapifyUp(parentIdx);
    }
}

#endif // MAXHEAP_H
