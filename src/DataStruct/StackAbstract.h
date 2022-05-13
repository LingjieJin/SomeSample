#include <stdint.h>
#include <stdbool.h>

typedef void Node;
typedef void *PNode;

typedef struct _StackAbstrct
{
    int size;
    PNode top;
} Stack, *PStack;

typedef struct _StackAPI
{
    Stack *(*Init)();
    /* 按照输入大小初始化 */
    Stack *(*Create)(int num);
    /* 销毁指定栈的内存 */
    bool (*Destroy)(Stack *stack);
    /* 将指定栈清空 即大小重置为0 */
    bool (*Clear)(Stack *stack);
    /* 压栈 */
    bool (*Push)(Stack *stack, Node *add_node);
    /* 删除栈顶元素 并返回该元素 如不需要请手动删除  */
    Node *(*Pop)(Stack *Stack);
    /* 返回栈顶元素 */
    Node *(*Peek)(Stack *stack);
    /* 判断栈是否为空 */
    bool (*isEmpty)(Stack *stack);
} StackAPI;

/* 保存实现函数 通过结构体调用 */
const StackAPI _ls_stack_api;
