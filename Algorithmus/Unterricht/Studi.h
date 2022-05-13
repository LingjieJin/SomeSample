//
//  Studi.h
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/18.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//
#ifndef Studi_h
#define Studi_h

#pragma once
class Studi
{
    public:
    Studi(char* n,char* v,char matri[],int t,int m,int j);
    ~Studi();
    char* name;
    char* vorname;
    char matrikel[9];
    int tag, monat, jahr;
    void Ausgeben();
};

bool kleiner(Studi*s1, Studi*s2);//Prototyp

#endif /* Studi_h */
