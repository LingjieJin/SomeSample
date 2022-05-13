/*

*/
#include "type.h"
#include "StackAbstract.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    Stack *stack = _ls_stack_api.Create(30);
    Node32_SP_t *node = _ls_stack_api.Peek(stack);
    node->elemData._uint32 = 999;

    Node32_SP_t *new_node = (Node32_SP_t *)malloc(sizeof(Node32_SP_t));
    new_node->elemData._uint32 = 666;
    _ls_stack_api.Push(stack, new_node);
    node = _ls_stack_api.Peek(stack);

    /**
     * top num:666
     * top next num:999
     * unknow num:0
     * stack size:31
     */
    printf("top num:%d\n", node->elemData._uint32);
    printf("top next num:%d\n", node->next->elemData._uint32);
    printf("unknow num:%d\n", node->next->next->elemData._uint32);
    printf("stack size:%d\n", stack->size);

    return 0;
}