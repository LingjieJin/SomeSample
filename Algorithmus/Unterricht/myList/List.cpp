//
//  List.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/25.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "List.h"

using namespace std;

template <typename T>
List<T>::List()
{
    this->head = nullptr; // 初始化list将头节点为空
}

template <typename T>
void List<T>::Add(T t)
{
    Node<T>* add = new Node<T>;
    add->data = t;
    add->link = nullptr;
    //
    if(this->head == nullptr)
        this->head = add;
    else
    {
        Node<T>* iterator = this->head;
        while (iterator != nullptr)
        {
            iterator = iterator->link;
        }
        iterator->link = add;
    }
}

template <typename T>
void List<T>::Delete(int n)
{
    
}
