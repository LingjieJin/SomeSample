#include <stdint.h>
#include <stdbool.h>
#include "type.h"

typedef void Node;
typedef void *PNode;
typedef void Queue;
typedef void *PQueue;

/**
 * -----------------------------------
 * | | | | | | | | | | | | | | | | |X|
 * -----------------------------------
 * ^                                ^
 * front                            rear (index)
 */
typedef struct _ArrayQueue
{
    int MaxSize;
    int front;
    int rear;
    UData32_t *array;
} ArrayQueue, *PArrayQueue;

typedef struct _QueueAbstract
{
    int MaxSize;
    int count;
    PNode front;
    PNode rear;
} ListQueue, *PListQueue;

typedef struct _QueueAPI
{
    Queue *(*Init)();
    /* 队列初始化 必须指定队列长度 */
    Queue *(*Create)(int size);
    bool (*isEmpty)(Queue *queue);
    bool (*Destroy)(Queue *queue);
    bool (*Clear)(Queue *queue);
    bool (*Enqueue)(Queue *queue, Node *node);
    Node *(*Dequeue)(Queue *queue);
    Node *(*GetFront)(Queue *queue);
    Node *(*GetRear)(Queue *queue);
    int (*GetSize)(Queue *queue);
} QueueAPI;

const QueueAPI _lq_queue_api;
const QueueAPI _sq_queue_api;