//
//  Node.h
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/25.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>

/* 单链表节点类 */

template<typename T>
class Node
{
private:
    T data;
    Node<T>* link;
public:
    Node():link(NULL){} // 默认构造函数
    Node(const T& val, Node<T>* next=NULL):data(val),link(next){}
    T& Data(){return data;}
    Node<T>* &Link(){return link;} // 返回数据成员link的值，函数返回类型定义为引用类型是为了使函数调用表达式能作为左值，可以作为赋值使用
};

/* 单链表表类 */

template<typename T>
class List
{
private:
    Node<T>* head;
public:
    List();
    ~List();
    void Add(T);
    void Delete(int n);
    void Insert(T, int n);
};

#endif /* Node_h */
