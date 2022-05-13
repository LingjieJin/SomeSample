//
//  LinearList.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/25.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class LinearList
{
public:
    LinearList();
    ~LinearList();
public:
    virtual bool IsEmpty() const=0;
    virtual int Length() const=0;
    // 增加 插入 删除 修改
    virtual bool Append(T x)const =0;
    virtual bool Insert(int i,T x)=0;
    virtual bool Delete(int i)=0;
    virtual bool Update(int i, T x) =0;
    //
    virtual bool Find(int i, T& x) const=0;
    virtual int Search(T x) const =0;
    virtual void Output(ostream& out)const=0;
public:
    int n;
};

