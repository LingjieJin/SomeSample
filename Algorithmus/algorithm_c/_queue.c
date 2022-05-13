#include "_queue.h"

void InitCQueue(CQueue pQueue)
{
    if (pQueue == NULL)
    {
        return ;
    }
    pQueue->front = 0;
    pQueue->rear = 0;    
}


void Push(CQueue pQueue, int val)
{
    if(IsFull(pQueue))
    {
        return;
    }

    pQueue->elem[pQueue->rear] = val;
    pQueue->rear = (pQueue->rear + 1)%MAXSIZE;
}

bool Pop(CQueue pQueue, int *rtval)
{
    if (IsEmpty(pQueue))
    {
        return false;
    }

    *rtval = pQueue->elem[pQueue->front];
    pQueue->front = (pQueue->front +1)% MAXSIZE;

    return true;
}

int GetCQueue(CQueue pQueue)
{
    return ((pQueue->rear - pQueue->rear + MAXSIZE)% MAXSIZE);
}

void ShwoQueue(CQueue pQueue)
{
    int front = pQueue->front;
    int rear = pQueue->rear;
    while (front != rear)
    {
        printf("%5d", pQueue->elem[front++]);
    }

    printf("\n");
}

bool IsEmpty(CQueue pQueue)
{
    return (pQueue->rear +1)% MAXSIZE == pQueue->front;
}

bool GetFront(CQueue pQueue, int *rtval)
{
    if( !IsEmpty(pQueue))
    {
        *rtval = pQueue->elem[pQueue->front];
        return true;
    }

    return false;
}

/*********************************************************/


void LQ_InitCQueue(LQueue pQueue)
{
    if (NULL == pQueue) //实际上就是初始化头结点
    {
        return;
    }
    pQueue->front = NULL;
    pQueue->rear = NULL;
}

LNode* LQ_BuyNode(int val)
{
    LNode* ptmp = (LNode*)malloc(sizeof(LNode));
    ptmp->data = val;
    ptmp->next = NULL;

    return ptmp;
}

void LQ_Push(LQueue pQueue, int val)
{
    LNode* pCur = LQ_BuyNode(val);
    if(pQueue->rear == NULL)
    {
        pQueue->front = pCur;
        pQueue->rear = pQueue->front;
    }
    else
    {
        pQueue->rear->next = pCur;
        pQueue->rear = pCur;
    }
}


bool LQ_Pop(LQueue pQueue, int* rtval)
{
    if( !LQ_IsEmpty(pQueue))
    {
        LNode* ptmp = pQueue->front;
        *rtval = ptmp->data;
        pQueue->front = ptmp->next;
        free(ptmp);
        if(pQueue->front == NULL)
        {
            pQueue->rear = pQueue->front;
        }

        return true;
    }

    return false;
}


int LQ_GetCQueueLen(LQueue pQueue)
{
    int iCount = 0;
    LNode *pCur = pQueue->front;
    while (pCur != NULL)
    {
        ++iCount;
        pCur= pCur->next;
    }
    
    return iCount;
}


void LQ_ShowQueue(LQueue pQueue)
{
    LNode *pCur = pQueue->front;
    while (NULL != pCur)
    {
        printf("%5d", pCur->data);
        pCur= pCur->next;
    }
    printf("\n");
}

bool LQ_IsEmpty(LQueue pQueue)
{
    return pQueue->front == NULL;
}

bool LQ_GetFront(LQueue pQueue, int *rtval)
{
    if (IsEmpty(pQueue))
    {
        return false;
    }
    *rtval = pQueue->front->data;
    return true;
}

void LQ_Destroy(LQueue pQueue)
{
    LNode *pCur = pQueue->front;
    LNode *pTmp;
    while (NULL != pCur)
    {
        pTmp= pCur->next;
        free(pCur);
        pCur= pTmp;
    }
}









