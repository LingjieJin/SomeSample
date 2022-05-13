//
//  QuickSort.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/23.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partitionieren(int array[], int le, int ri)
{
    if(le>=ri)
    {
        return 0;
    }
    int left = le;
    int right = ri;
    int pivot = array[le];
    while(left < right)
    {
        while (array[right] >= pivot && left<right)
            right--;
        array[left] = array[right];
        while (pivot >= array[left] && left<right)
            left++;
        array[right] = array[left];
    }
    array[left] = pivot;
    
    return 0;
}

void QuickSort(int array[], int le, int ri)
{
    if(le>=ri)
    {
        return ;
    }
    
    int left = le;
    int right = ri;
    int pivot = array[left];
    
    cout<<"选取"<<pivot<<"作为key值, 在数组";
    for(int i=le;i<=ri;i++)
    {
        cout<<" "<<array[i];
    }
    cout<<endl;
    
    while(left < right)
    {
        while ((array[right] > pivot) && left<right)
            right--;
        array[left] = array[right];
        while ((pivot >= array[left]) && left<right)
            left++;
        array[right] = array[left];
    }
    array[left] = pivot;
    cout<<"完成一次快速排序"<<endl;
    for(int i=le;i<=ri;i++)
    {
        cout<<" "<<array[i];
    }
    cout<<endl;
    
    QuickSort(array, le, left-1);
    QuickSort(array, left+1, ri);
    
}


/*
int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    //char array[] = {'A', 'v','H', 's', 'q','Z','m','E'};
    //
    cout<<"原始数组排列：";
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    QuickSort(arr, 0, 10);
    
    cout<<"最终数组排列：";
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    
    return  0;
}

*/



