

#include <iostream>
using namespace std;


template<typename T>
class LoopQueue
{
    public:
        LoopQueue(int c = 10);
        ~LoopQueue();
        bool isEmpty();
        int size();
        bool push(T t);
        bool pop();
        T front();
    private:
        int capacity;
        int begin;
        int end;
        T* queue;
};

template<typename T>
LoopQueue<T>::LoopQueue(int c = 10):capacity(c), begin(0), queue(nullptr)
{
    queue = new T[capacity];
}

template<typename T>
LoopQueue<T>::~LoopQueue()
{
    delete[] queue;
}

template<typename T>
bool LoopQueue<T>::isEmpty()
{
    if(begin == end)
    {
        return true;
    }

    return false;
}

template<typename T>
int LoopQueue<T>::size()
{
    return (end - begin + capacity) % capacity;
}

template<typename T>
bool LoopQueue<T>::push(T t)
{
    if(end + 1 % capacity == begin)
    {
        return false;
    }
    queue[end] = t;
    end = (end + 1) % capacity;

    return true;
}

template<typename T>
bool LoopQueue<T>::pop()
{
    if( end == begin)
    {
        return false;
    }
    begin = (begin + 1) % capacity;

    return true;
}

template<typename T>
T LoopQueue<T>::front()
{
    if(end == begin)
    {
        return false;
    }

    return queue[begin];
}


























