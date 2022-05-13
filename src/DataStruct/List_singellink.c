#include "type.h"
#include "ListAbstract.h"

#include <stdio.h>
#include <stdlib.h>

static List *_Init()
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    if (list == NULL)
    {
        return NULL;
    }
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

static List *_Create(int num)
{
    LinkList *list = _Init();

    for (int i = 0; i < num; i++)
    {
        Node32_SP_t *new_node = (Node32_SP_t *)malloc(sizeof(Node32_SP_t));
        if (new_node == NULL)
        {
            return NULL;
        }
        new_node->next = NULL;
        new_node->elemData._uint32 = 0;

        if (list->head == NULL)
        {
            list->head = new_node;
        }
        else
        {
            ((Node32_DP_t *)list->tail)->next = new_node;
        }

        list->tail = new_node;
    }

    list->size = num;
    return list;
}

static bool _Destroy(List *list)
{
    Node32_SP_t *cursor;
    for (int i = 0; i < ((LinkList *)list)->size; i++)
    {
        cursor = (Node32_SP_t *)((LinkList *)list)->head;
        ((LinkList *)list)->head = ((Node32_SP_t *)((LinkList *)list)->head)->next;
        free(cursor);
    }
    free(((LinkList *)list));
    return true;
}

static bool _isEmpty(List *list)
{
    return ((LinkList *)list)->size == 0;
}

static Node *_Select(List *list, int index)
{
    if (((LinkList *)list)->size <= index)
    {
        return NULL;
    }

    Node32_SP_t *node = (Node32_SP_t *)((LinkList *)list)->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

static int _Append(List *list, Node *add_node)
{
    if (((LinkList *)list)->head == NULL)
    {
        ((LinkList *)list)->head = (Node32_SP_t *)add_node;
    }
    else
    {
        ((Node32_SP_t *)((LinkList *)list)->tail)->next = (Node32_SP_t *)add_node;
    }
    ((LinkList *)list)->tail = add_node;

    return ((LinkList *)list)->size++;
}

static int _Insert(List *list, Node *add_node, int index)
{
    if (((LinkList *)list)->size <= index)
    {
        return 0;
    }

    Node32_SP_t *node = (Node32_SP_t *)((LinkList *)list)->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    if (index == 0)
    {
        ((Node32_SP_t *)add_node)->next = node;
        ((LinkList *)list)->head = (Node32_SP_t *)add_node;
    }
    else
    {
        ((Node32_SP_t *)add_node)->next = node;
        for (int i = 0; i < index; i++)
        {
            
        }
        
    }

    return ((LinkList *)list)->size++;
}