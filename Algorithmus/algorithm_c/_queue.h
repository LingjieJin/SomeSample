#ifndef _QUEDE_H
#define _QUEDE_H

#include "_unistd.h"

typedef struct _node
{
    Node* next;
    
}Node;


#define MAXSIZE 10

typedef struct _CNode
{
    int elem[MAXSIZE];
    int front; //下标可取,指向队头元素
    int rear; //下标不可取,指向元素应放入的位置
}CNode, *CQueue;


void InitCQueue(CQueue pQueue); //初始化队列
void Push(CQueue pQueue, int val); //入队，从队尾(rear)入
bool Pop(CQueue pQueue, int *rtval); //出队，从队首(front)出
int GetCQueueLen(CQueue pQueue); //获取队列长度
void ShowQueue(CQueue pQueue); //输出队列所有元素
bool IsEmpty(CQueue pQueue); //队列为空则返回true
bool IsFull(CQueue pQueue); //队列满则返回false
bool GetFront(CQueue pQueue, int *rtval); //获取队首元素


/**************************************************/

typedef struct _LNode
{
    int data;
    struct _LNode *next;
}LNode;

typedef struct _LQueue
{
    LNode *front;
    LNode *rear;
}Queue, *LQueue;

void LQ_InitCQueue(LQueue pQueue); //初始化队列
LNode* LQ_BuyNode(int val); //从堆中申请一个节点的内存空间
void LQ_Push(LQueue pQueue, int val); //入队，从队尾(rear)入
bool LQ_Pop(LQueue pQueue, int *rtval); //出队，从队首(front)出
int LQ_GetLQueueLen(LQueue pQueue); //获取队列长度
void LQ_ShowQueue(LQueue pQueue); //输出队列所有元素
bool LQ_IsEmpty(LQueue pQueue); //队列为空则返回true
bool LQ_GetFront(LQueue pQueue, int *rtval); //获取队首元素
void LQ_Destroy(LQueue pQueue); //销毁队列(释放所有节点的内存空间)




#endif