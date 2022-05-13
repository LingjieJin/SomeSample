//
//  AlgorithmusSeqList.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/25.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include "SeqList.cpp"

template <typename T>
void Union(SeqList<T> &LA, SeqList<T> &LB)
{
    T x;
    for(int i=0;i<LB.Length();i++)
    {
        LB.Find(i, x);
        if(LA.Search(x) == -1)
            LA.Insert(LA.Length()-1, x);
    }
}

int main()
{
    SeqList<int> La(20);
    SeqList<int> Lb(20);
    for(int i=0;i<5;i++) La.Insert(i, i);
    for(int j=5;j<10;j++) Lb.Insert(j-5, j);
    La.Output(cout);
    Lb.Output(cout);
    //
    Lb.Insert(0, 0);
    Lb.Output(cout);
    Lb.Insert(3, 2);
    Lb.Output(cout);
    Lb.Insert(Lb.Length()-1, 4);
    Lb.Output(cout);
    Union(La, Lb);
    La.Output(cout);
    
    return 0;
}
