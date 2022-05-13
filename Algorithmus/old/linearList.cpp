//
//  linearList.cpp
//  AlgorithmAndDatenstruck
//
//  Created by kIng_martin on 2018/11/6.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>

template <typename T>
class linearlist
{
public:
    linearlist();
    ~linearlist();
public:
    virtual bool IsEmpty();
    virtual int Length();
    virtual int Add(T x);
    virtual int Delete(int index);
    virtual int Update(int index, T x);
    virtual int Search(T x);
public:
    int count;
};
