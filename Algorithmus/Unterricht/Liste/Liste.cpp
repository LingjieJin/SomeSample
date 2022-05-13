//
//  liste.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/24.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//
#include "Liste.h"

template<class T>
Liste<T>::Liste()
{
    erstesElement=nullptr;
}

template <class T>
Element<T>* Liste<T>::getErsteElement()
{
    return erstesElement;
}

template<class T>
void Liste<T>::Add(T x){
    Element<T> *neu = new Element<T>(); // 新建一个存储元素
    neu->inhalt=x;
    neu->next=nullptr;
    if(erstesElement==nullptr)          // 如果链表是空的 则加入为第一个元素
        erstesElement=neu;
    else
    {
        // 遍历该链表，找到最后一个元素
        Element<T> *it=erstesElement;
        while(it->next!=nullptr)
        {
            it=it->next;//
        }
        it->next=neu;// 链表最后一个元素指针指向新的元素
    }
    
}

template<class T>
void Liste<T>::Insert(T x, std::function<bool (T, T)> kleiner)
{
    Element<T> *neu = new Element<T>;
    neu->inhalt = x;
    neu->next = nullptr;
    //
    if(erstesElement==nullptr)          // 如果链表是空的 则加入为第一个元素
        erstesElement=neu;
    //
    Element<T> *it = erstesElement;
    int position = 0;
    while(it->next != nullptr)
    {
        if(kleiner(x,it->inhalt)==true)
            break;
        it = it->next;
        position++;
    }
    //
    it = erstesElement;
    for(int i =0;i<position;i++)
    {
        it = it->next;
    }
    Element<T> *temp = it->next;
    it->next = neu;
    neu->next = temp;
}


template<class T>
int Liste<T>::Length()
{
    //从链表第一个元素开始遍历
    Element<T> *it=erstesElement;
    int counter=0;
    while(it!=nullptr)
    {
        it=it->next;
        counter++;
    }
    return counter;
}

template <class T>
int Liste<T>::rekLength(Element<T>* element)
{
    if(element == nullptr)
        return 0;
    else
        return 1+rekLength(element->next);
}

template<class T>
bool Liste<T>::Remove(std::function<bool (T)> pred)
{
    if(erstesElement == nullptr)
        return false;
    if(pred(erstesElement->inhalt) == true)
    {
        Element<T> *aus = erstesElement;
        erstesElement = aus->next; //把第二个元素作为第一个元素
        delete aus;
        return true;
    }
    else
    {
        Element<T>* voriges = erstesElement;
        while((voriges->next!=nullptr) &&
              (pred(voriges->next->inhalt)==false))
        {
            voriges=voriges->next; // Weiterruecken in der Liste
        }
        if(voriges->next!=nullptr)
        {// falls gefunden:
            Element<T> *aux=voriges->next;
            // zu löschendes Element ist voriges->next
            // Zeiger umstellen von voriges auf übernächstes voriges->next=voriges->next->next;
            delete aux; return true;// Speichermüll löschen
        } else
            return false;
    }
}


template<class T>
void Liste<T>::show(std::function<void (T)> Ausgeben)
{
    Element<T>* it = erstesElement;
    while (it->next != nullptr)
    {
        Ausgeben();
        it = it->next;
    }
}






