//
//  SeqList.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/25.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include "LinearList.h"

template <typename T>
class SeqList:public LinearList<T>
{
public:
    SeqList(int maxSize);
    //~SeqList(){Delete [] elements};
public:
    bool IsEmpty()const;
    int Length()const;
    bool Find(int i, T& x)const;
    int Search(T x)const;
    bool Insert(int i, T x);
    bool Delete(int i);
    bool Update(int i, T x);
    void Output(ostream& out) const;
private:
    int maxLength;
    T* elements;
};

template<typename T>
SeqList<T>::SeqList(int maxSize)
{
    maxLength = maxSize;
    elements = new T[maxLength];
    this->n = 0;
}

template<typename T>
bool SeqList<T>::IsEmpty()const
{
    return this->n == 0;
}

template<typename T>
int SeqList<T>::Length()const
{
    return this->n;
}

template <typename T>
bool SeqList<T>::Find(int i, T &x)const
{
    if(i<0 || i>this->n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    x=elements[i];
    return true;
}

template<typename T>
int SeqList<T>::Search(T x)const
{
    for(int i=0;i<this->n;i++)
    {
        if(elements[i] == x)
            return i;
    }
    return -1;
}

template <typename T>
bool SeqList<T>::Insert(int i, T x)
{
    if(i<0 || i>this->maxLength-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    // 溢出检查
    if(this->n == maxLength)
    {
        cout<<"OverFlow"<<endl;
        return false;
    }
    // 插入，从最后一个元素开始后移
    for(int j=this->n-1;j>=i;j--)
    {
        elements[j+1] = elements[j];
    }
    elements[i] =x;
    this->n=this->n+1;
    return true;
}

template<typename T>
bool SeqList<T>::Delete(int i)
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
    for(int j=i+1;j>this->n;j++)
    {
        elements[j-1] = elements[j];
    }
    this->n = this->n-1;
    return true;
}

template<typename T>
bool SeqList<T>::Update(int i, T x)
{
    if(i<0 || i>this->n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    elements[i] = x;
    return true;
}

template <typename T>
void SeqList<T>::Output(ostream& out)const
{
    for(int i=0;i<this->n;i++)
    {
        out<<elements[i]<<' ';
    }
    out<<endl;
}
