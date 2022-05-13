//
//  SingleList.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/25.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include "LinearList.h"

template<typename T>
class Node
{
private:
    T element;
    Node<T>* link;
};

template <typename T>
class SingleList:public LinearList<T>
{
private:
    Node<T>* first;
public:
    SingleList(){first = nullptr; this->n =0;}
    ~SingleList();
public:
    bool IsEmpty()const;
    int Length()const;
    bool Find(int i, T& x)const;
    int Search(T x)const;
    bool Insert(int i, T x);
    bool Delete(int i);
    bool Update(int i, T x);
    void Output(ostream& out) const;
public:
    void Clear();
};

template<typename T>
SingleList<T>:: ~SingleList()
{
    Node<T>* p;
    while (first)
    {
        p = first->link;
        delete first;
        first = p;
    }
}

template<typename T>
int SingleList<T>::Length()const
{
    return this->n;
}

template<typename T>
bool SingleList<T>::IsEmpty()const
{
    return this->n == 0;
}

template<typename T>
bool SingleList<T>::Find(int i, T &x)const
{
    if(i<0 || i>this->n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    Node<T>* p=first;
    for(int j=0;j<i;j++)
    {
        p = p->link;
    }
    x = p->element;
    return true;
}

template<typename T>
int SingleList<T>::Search(T x)const
{
    Node<T>* p = first;
    int j;
    for(j =0;p&&p->element!=x;j++)
    {
        p = p->link;
    }
    if(p)
        return j;
    return -1;
}

template<typename T >
bool SingleList<T>::Insert(int i, T x)
{
    if(i<0 || i>this->n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    Node<T>* neu = new Node<T>;
    neu->element = x;
    Node<T>* p = first;
    for(int j=0;j<i;j++)
    {
        p = p->link;
    }
    if(i>-1)
    {
        neu->link = p->link;
        p->link = neu;
    }
    else
    {
        neu->link = first;
        first = neu;
    }
    this->n++;
    return true;
}

template<typename T>
bool SingleList<T>::Delete(int i)
{
    if(!this->n)
    {
        cout<<"UnderFlow"<<endl;
        return false;
    }
    if(i<0 || i>this->n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    Node<T> *p = first, *q = first;
    for(int j=0;j<i-1;j++)
    {
        q = q->link;
    }
    if(i == 0)
    {
        first = first->link;
    }
    else
    {
        p = q->link;
        q->link = p->link;
    }
    delete p;
    this->n--;
    return true;
}

template<typename T>
bool SingleList<T>::Update(int i, T x)
{
    if(i<0 || i>this->n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    Node<T> *p = first;
    for(int j=0;j<i;j++)
    {
        p = p->link;
    }
    p->element = x;
    return  true;
}

template <typename T>
void SingleList<T>::Clear()
{
    
}

template<typename T>
void SingleList<T>::Output(ostream &out)const
{
    Node<T> *p = first;
    while (p)
    {
        cout<<p->element<<" ";
        p = p->link;
    }
    out<<endl;
}

