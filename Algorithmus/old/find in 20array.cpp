//
//  find in 20array.cpp
//  Algorithmus and Datestruktur
//
//  Created by kIng_martin on 2018/10/29.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20

int main()
{
    int arr[N],x,n,i;
    int f=1;
    //
    srand(time(NULL));
    for(i=0;i<N;i++)
    {
        arr[i] = rand()/1000;
    }
    printf("\n 随机生成的数组是:\n");
    for (i=0; i<N; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    //
    printf("请输入要查找的数字:");
    scanf("%d", &x);
    //
    for(i=0;i<N;i++)
    {
        if(x==arr[i])
        {
            f=i;
            break;
        }
    }
    //
    if(f<0)
    {
        printf("查找不到所需数字:%d\n",x);
    }
    else
    {
        printf("所找数据%d 在数组的 第%d个 位置\n",x,f+1);
    }
    //
    return 0;
}
