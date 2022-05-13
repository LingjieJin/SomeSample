//
//  BinarySearch.cpp
//  Algorithmus
//
//  Created by kIng_martin on 2018/10/18.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include "Algorithmus.h"

template<typename T>
T BinarySearch(T array[], int n, T target)
{
    int head = 0;
    int end = n-1;
    while(head <= end)
    {
        int mid = (head + end)/2;
        if(array[mid] == target)
            return array[mid];
        else if(array[mid] < target)
        {
            head = mid +1;
        }
        else{
            end = mid -1;
        }
            
    }
    return nullptr;
}
