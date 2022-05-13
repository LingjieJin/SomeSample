//
//  BubbleSort.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/22.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//数组按照**升序排列**
template<typename T>
int BubbleSort_me(T array[], int n)
{
    T temp;
    for(int i = 1; i<n;i++)
    {
        for(int j = i;j>0;j--)
        {
            if(array[j]<array[j-1])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
    
    return 0;
}
//数组按照**升序排列**
template<typename T>
void BubbleSort(T array[], int n)
{
    //
    cout<<"原始数组排列：";
    for(int i=0;i<11;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    //
    T temp;
    for(int i = 0; i<n-1;i++)//最后一个不需要检查
    {
        cout<<"第"<<i<<"次冒泡开始:"<<endl;;
        for(int j =0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])//如果当前数比后一个数大，则交换两者位置。
            {
                cout<<"/t"<<"交换"<<j<<" 和 "<<j+1<<"的位置"<<endl;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                for(int i=0;i<n;i++)
                {
                    cout<<array[i]<<" ";
                }
                cout<<endl;
            }
        }
        cout<<"第"<<i<<"次冒泡完成";
        for(int i=0;i<n;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    
}

/*
int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    char array[] = {'A', 'v','H', 's', 'q','Z','m','E'};
    //
    cout<<"原始数组排列：";
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    BubbleSort(arr, 11);
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //
    cout<<"原始数组排列：";
    for(int i=0;i<8;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    BubbleSort(array, 8);
    for(int i=0;i<8;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    //
    return  0;
}

*/
