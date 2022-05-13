//
//  linklist.cpp
//  AlgorithmAndDatenstruck
//
//  Created by kIng_martin on 2018/11/6.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>

template <typename T>
class Node
{
    T data;
    Node<T>* next;
    Node<T>* up;
};

template<typename T>
class linklist
{
private:
    Node<T>* head;
    int max;
    int count;
public:
    linklist();
    ~linklist();
public:
    int Add(int index, T x);
};

template<typename T>
int linklist<T>::Add(int index, T x)
{
    if(count >= max)
        return -1;
    Node<T>* newNode = new Node<T>();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->up = nullptr;
    //
    Node<T>* itrator = head;
    for(int i=0;i<index;i++)
    {
        itrator=itrator->next;
    }
    newNode->next = itrator->next;
}

