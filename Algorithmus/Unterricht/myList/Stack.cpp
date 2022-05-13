//
//  Stack.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/29.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include "LinearList.h"

template<typename T>
class Stack:public LinearList<T>
{
public:
    bool Append(T x)const =0;
};

template<typename T>
bool Stack<T>::Append(T x)const
{
    
}
