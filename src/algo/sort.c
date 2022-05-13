#include <stdio.h>

#include <stdint.h>

void printArray(int *arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (i % 8 == 7)
            printf("\n");
        printf("%d \t", *(arr + i));
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_exclusive(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/* 泛型交换 */
void swap_ge(void *a, void *b, size_t type_size)
{
    char *p1 = (char *)a;
    char *p2 = (char *)b;
    char temp;
    while (type_size--)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2++;
    }
}

/**
 * 冒泡排序
 * 
 * 从数据首位开始 逐位与后一位比较大小
 * 每一轮当前首位都与后面所有数据比较
 * 排序结果为升序
 */
void bubbleSort(int *arr, int length, int debug)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            /* 升序 */
            if ((*(arr + i)) > (*(arr + j)))
                swap(arr + i, arr + j);
        }

        if (debug)
        {
            /* debug print */
            printf("%d:\n", i + 1);
            printArray(arr, length);
            printf("\n");
        }
    }
}

/**
 * 插入排序
 */

/* 数组后移一位 */
void arrayMove(int *arr, int pre, int aft, int n)
{
}

void InsertSort(int *arr, int length, int debug)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            /* 升序 */
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
            }
        }

        if (debug)
        {
            /* debug print */
            printf("%d:\n", i);
            printArray(arr, length);
            printf("\n");
        }
    }
}

void SelectSort(int *arr, int length, int debug)
{
    for (int i = 0; i < length; i++)
    {
        int key = i;
        for (int j = i + 1; j < length; j++)
        {
            /* 升序 */
            if (arr[key] > arr[j])
            {
                key = j;
            }
        }
        if (key != i)
            swap(arr + key, arr + i);

        if (debug)
        {
            /* debug print */
            printf("%d:\n", i + 1);
            printArray(arr, length);
            printf("\n");
        }
    }
}

void createHeap(int *arr, int i, int size)
{
    // 注意数组是从0开始计数，所以左节点为2*i+1，右节点为2*i+2
    for (; i >= 0; --i)
    {
        int left = i * 2 + 1;  //左子树节点
        int right = i * 2 + 2; //右子树节点
        int j = 0;
        //选出左右子节点中最大的
        if (right < size)
        {
            arr[left] > arr[right] ? (j = left) : (j = right);
        }
        else
        {
            j = left;
        }
        //交换子节点与父节点
        if (arr[j] > arr[i])
        {
            swap(arr + i, arr + j);
        }
    }
}

//    进行堆排序，依次选出最大值放到最后面
void HeapSort(int *arr, int n, int debug)
{
    //初始化构造堆
    createHeap(arr, n / 2 - 1, n);
    //交换第一个元素和最后一个元素后，堆的大小减1
    for (int j = n - 1, count = 0; j >= 0; j--, count++)
    {

        //最后一个元素和第一个元素进行交换
        swap(arr, arr + j);

        int i = j / 2 - 1;
        createHeap(arr, i, j);

        if (debug)
        {
            /* debug print */
            printf("%d:\n", count + 1);
            printArray(arr, n);
            printf("\n");
        }
    }
}