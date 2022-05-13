#include "QueueAbstract.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

static bool _Enqueue(Queue *queue, Node *node);
static Node *_Dequeue(Queue *queue);

static bool _isEmpty(Queue *queue)
{
    return ((ListQueue *)queue)->count == 0;
}

static Queue *_Init()
{
    ListQueue *queue = (ListQueue *)malloc(sizeof(ListQueue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->MaxSize = queue->count = 0;
    queue->front = queue->rear = NULL;

    return queue;
}

static Queue *_Create(int size)
{
    ListQueue *queue = _Init();
    queue->MaxSize = size;

    /**/

    return queue;
}

static bool _Destroy(Queue *queue)
{
    if (queue == NULL)
    {
        return true;
    }

    while (((ListQueue *)queue)->count)
    {
        Node32_SP_t *temp = (Node32_SP_t *)_Dequeue(queue);
        free(temp);
    }

    free(queue);

    return true;
}

static bool _Clear(Queue *queue)
{
    if (queue == NULL)
    {
        return true;
    }

    while (((ListQueue *)queue)->count)
    {
        Node32_SP_t *temp = (Node32_SP_t *)_Dequeue(queue);
        free(temp);
    }

    return true;
}

static bool _Enqueue(Queue *queue, Node *node)
{
    if (queue == NULL || ((ListQueue *)queue)->count >= ((ListQueue *)queue)->MaxSize)
    {
        return false;
    }
    /* 可选操作 */
    ((Node32_SP_t *)node)->next = NULL;

    /* 当队列为空时 加入操作不同 */
    if (((ListQueue *)queue)->front == NULL)
    {
        ((ListQueue *)queue)->front = node;
    }
    else
    {
        ((Node32_SP_t *)((ListQueue *)queue)->rear)->next = (Node32_SP_t *)node;
    }
    ((ListQueue *)queue)->rear = node;
    ((ListQueue *)queue)->count++;

    return true;
}

static Node *_Dequeue(Queue *queue)
{
    if (queue == NULL || ((ListQueue *)queue)->count == 0)
    {
        return NULL;
    }

    Node32_SP_t *ret = ((ListQueue *)queue)->front;
    ((ListQueue *)queue)->front = ((Node32_SP_t *)((ListQueue *)queue)->front)->next;
    ((ListQueue *)queue)->count--;

    /* 队列仅有一个元素时候 删除后需要检查 */
    if (((ListQueue *)queue)->front == NULL)
    {
        ((ListQueue *)queue)->rear = NULL;
    }

    return ret;
}

static Node *_GetFront(Queue *queue)
{
    return ((ListQueue *)queue)->front;
}

static Node *_GetRear(Queue *queue)
{
    return ((ListQueue *)queue)->rear;
}

static int _GetSize(Queue *queue)
{
    return ((ListQueue *)queue)->count;
}

const QueueAPI _lq_queue_api = {
    _Init,
    _Create,
    _isEmpty,
    _Destroy,
    _Clear,
    _Enqueue,
    _Dequeue,
    _GetFront,
    _GetRear,
    _GetSize,
};