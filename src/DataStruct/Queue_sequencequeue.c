#include "QueueAbstract.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool _isFull(Queue *queue)
{
    return (((((ArrayQueue *)queue)->front + 1) % ((ArrayQueue *)queue)->MaxSize) == ((ArrayQueue *)queue)->rear);
}

static Queue *_Init()
{
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    queue->MaxSize = 0;
    queue->front = queue->rear = 0;
    queue->array = NULL;

    return queue;
}

static Queue *_Create(int size)
{
    ArrayQueue *queue = (ArrayQueue *)_Init();
    UData32_t *data_array = (UData32_t *)malloc(sizeof(UData32_t) * size);
    if (data_array == NULL)
    {
        return NULL;
    }

    queue->array = data_array;
    queue->MaxSize = size;

    return queue;
}

static bool _isEmpty(Queue *queue)
{
    return (((ArrayQueue *)queue)->front == ((ArrayQueue *)queue)->rear);
}

static bool _Destroy(Queue *queue)
{
    free(((ArrayQueue *)queue)->array);
    free(((ArrayQueue *)queue));

    return true;
}

static bool _Clear(Queue *queue)
{
    if (_isEmpty(queue))
    {
        return true;
    }

    /* 数据清空 */
    for (int i = 0; i < ((ArrayQueue *)queue)->MaxSize; i++)
    {
        ((ArrayQueue *)queue)->array[i]._uint32 = 0;
    }

    ((ArrayQueue *)queue)->front = ((ArrayQueue *)queue)->rear = 0;
}

static bool _Enqueue(Queue *queue, Node *node)
{
    memcpy(&((ArrayQueue *)queue)->array[((ArrayQueue *)queue)->rear], node, sizeof(UData32_t));
    ((ArrayQueue *)queue)->rear = (((ArrayQueue *)queue)->rear + 1) % ((ArrayQueue *)queue)->MaxSize;
}

static Node *_Dequeue(Queue *queue)
{
    UData32_t *delete_node = (UData32_t *)malloc(sizeof(UData32_t));
    memcpy(delete_node, &((ArrayQueue *)queue)->array[((ArrayQueue *)queue)->front], sizeof(UData32_t));
    ((ArrayQueue *)queue)->front = (((ArrayQueue *)queue)->front + 1) % ((ArrayQueue *)queue)->MaxSize;
    return delete_node;
}

static Node *_GetFront(Queue *queue)
{
    return &((ArrayQueue *)queue)->array[((ArrayQueue *)queue)->front];
}

static Node *_GetRear(Queue *queue)
{
    return &((ArrayQueue *)queue)->array[(((ArrayQueue *)queue)->rear - 1)];
}

static int _GetSize(Queue *queue)
{
    if (((ArrayQueue *)queue)->rear >= ((ArrayQueue *)queue)->front)
    {
        return ((ArrayQueue *)queue)->rear - ((ArrayQueue *)queue)->front;
    }
    else
    {
        return ((ArrayQueue *)queue)->rear + ((ArrayQueue *)queue)->MaxSize - ((ArrayQueue *)queue)->front;
    }
}

const QueueAPI _sq_queue_api = {
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
