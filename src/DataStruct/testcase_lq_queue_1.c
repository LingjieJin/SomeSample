/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "type.h"
#include "QueueAbstract.h"

int main()
{
    srand(time(0));
    ListQueue *queue = _lq_queue_api.Create(100);

    if (queue == NULL)
    {
        printf("cant create queue!\n");
        return 0;
    }

    for (int i = 0; i < 50; i++)
    {
        Node32_SP_t *new_node = (Node32_SP_t *)malloc(sizeof(Node32_SP_t));
        new_node->elemData._uint32 = rand() % 100;
        _lq_queue_api.Enqueue(queue, new_node);
    }

    Node32_SP_t *cursor = queue->front;
    for (size_t i = 0; i < 50; i++)
    {
        printf("index %d, %d\n", i, cursor->elemData._uint32);
        cursor = cursor->next;
    }

    UData32_t get_1 = ((Node32_SP_t *)_lq_queue_api.GetFront(queue))->elemData;
    UData32_t get_2 = ((Node32_SP_t *)_lq_queue_api.GetRear(queue))->elemData;
    int size = _lq_queue_api.GetSize(queue);
    printf("front %d, rear %d, size %d.\n", get_1._uint32, get_2._uint32, size);

    return 0;
}