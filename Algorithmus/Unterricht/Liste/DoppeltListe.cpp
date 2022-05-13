//
//  DoppeltListe.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/24.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>

template<class T>
class Element
{
public:
    T inhalt;
    Element* next;
    Element* prev;
};

template <class T>
class DoppelListe
{
private:
    Element<T>* head;
    Element<T>* tail;
    
public:
    int Add(T);
    int Delete(int n);
    
};
