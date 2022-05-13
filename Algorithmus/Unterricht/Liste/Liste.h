//
//  Liste.h
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/24.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#ifndef Liste_h
#define Liste_h

#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class Element
{
public:
    T inhalt;
    Element* next;
};

template<class T>
class Liste
{
private:
    Element<T>* erstesElement;
public:
    Liste();
    void Add(T);
    bool Remove(std::function<bool (T)>);
    int Length();
    int rekLength(Element<T>* element);
    
    void Insert(T, std::function<bool (T,T)>);
    void show(std::function<void (T)>);
    
    Element<T>* getErsteElement();
};

#endif /* Liste_h */
