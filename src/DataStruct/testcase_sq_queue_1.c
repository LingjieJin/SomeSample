/*
 gcc SQ_Queue.c testcase_sq_queue_1.c -o 1.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "QueueAbstract.h"

int main()
{
    srand(time(NULL));
    ArrayQueue *queue = _sq_queue_api.Create(50);

    for (int i = 0; i < 50; i++)
    {
        UData32_t add;
        add._uint32 = rand() % 100;
        _sq_queue_api.Enqueue(queue, (UData32_t *)&add);
    }

    for (size_t i = 0; i < 50; i++)
    {
        printf("index %d, %d\n", i, queue->array[i]._uint32);
    }

    UData32_t *get_1 = (UData32_t *)_sq_queue_api.GetFront(queue);
    UData32_t *get_2 = (UData32_t *)_sq_queue_api.GetRear(queue);
    int size = _sq_queue_api.GetSize(queue);

    printf("front %d, rear %d, size %d.\n", get_1->_uint32, get_2->_uint32, size);

    return 0;
}
