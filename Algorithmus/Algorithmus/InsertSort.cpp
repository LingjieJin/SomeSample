//
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/16.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//
#include <iostream>

template<typename T>
int InsertSort(T array[], int n)
{
    
    return 0;
}

/*
 按照从小到大的顺序排列
 */
void InsertSort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = a[i];
        int j = i-1;
        while( j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        
    }
}

void InsertionSort_Internet(int A[], int n)
{
    for (int i = 1; i < n; i++)         // 类似抓扑克牌排序
    {
        int get = A[i];                 // 右手抓到一张扑克牌
        int j = i - 1;                  // 拿在左手上的牌总是排序好的
        while (j >= 0 && A[j] > get)    // 将抓到的牌与手牌从右向左进行比较
        {
            A[j + 1] = A[j];            // 如果该手牌比抓到的牌大，就将其右移
            j--;
        }
        A[j + 1] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
    }
}
