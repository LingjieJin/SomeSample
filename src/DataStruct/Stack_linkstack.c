#include "StackAbstract.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

static bool _Push(Stack *stack, Node *add_node);
static Node *_Pop(Stack *stack);

static Stack *_Init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

static Stack *_Create(int num)
{
    if (num <= 0)
        return NULL;

    Stack *stack = _Init();

    while (num)
    {
        Node32_SP_t *new_node = (Node32_SP_t *)malloc(sizeof(Node32_SP_t));
        new_node->next = NULL;
        new_node->elemData._uint32 = 0;
        _Push(stack, new_node);

        num--;
    }

    return stack;
}

static bool _Destroy(Stack *stack)
{
    Node32_SP_t *temp;

    while (stack->top != NULL)
    {
        temp = (Node32_SP_t *)_Pop(stack);
        free(temp);
    }

    free(stack);

    return true;
}

static bool _Clear(Stack *stack)
{
    Node32_SP_t *temp;

    while (stack->top != NULL)
    {
        temp = (Node32_SP_t *)_Pop(stack);
        free(temp);
    }

    return true;
}

static bool _Push(Stack *stack, Node *add_node)
{
    ((Node32_SP_t *)add_node)->next = (Node32_SP_t *)stack->top;
    stack->top = (Node32_SP_t *)add_node;

    stack->size++;
    return true;
}

static Node *_Pop(Stack *stack)
{
    if (stack->size <= 0)
    {
        return NULL;
    }

    Node32_SP_t *temp = stack->top;
    stack->top = ((Node32_SP_t *)stack->top)->next;

    stack->size--;
    return temp;
}

static Node *_Peek(Stack *stack)
{
    return stack->top == NULL ? NULL : stack->top;
}

static bool _isEmpty(Stack *stack)
{
    return (stack->size == 0);
}

const StackAPI _ls_stack_api = {
    _Init,
    _Create,
    _Destroy,
    _Clear,
    _Push,
    _Pop,
    _Peek,
    _isEmpty,
};