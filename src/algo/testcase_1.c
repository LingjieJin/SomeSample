#define _DEBUG

#include "sort.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{

    srand(time(0));
    int arr[10];
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        arr[i] = rand() % 100;
    }

    printf("src:\n");
    printArray(arr, 10);
    // bubbleSort(arr, 10, 1);

    // InsertSort(arr, 10, 1);

    // SelectSort(arr, 10, 1);

    HeapSort(arr, 10, 1);

    return 0;
}