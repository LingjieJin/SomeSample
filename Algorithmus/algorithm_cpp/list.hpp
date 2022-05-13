#ifndef LIST_HPP
#define LIST_HPP


#include <iostream>

using namespace std;

template<typename T>
struct MyNode
{
    T data;
    MyNode* next;
    MyNode* prev;
};


template<typename T>
class MyList
{
private:
    MyNode* head;
    MyNode* tail;
    MyNode* current;
    int number;
public:
    MyList<T>()
    {
        head = new MyNode<T>();
        head->next = NULL;
        head->prev = NULL;
    }
    ~MyList();
};






#endif