#include "ListAbstract.h"
#include "type.h"
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
        Node32_DP_t *new_node = (Node32_DP_t *)malloc(sizeof(Node32_DP_t));
        if (new_node == NULL)
        {
            return NULL;
        }
        new_node->prev = new_node->next = NULL;
        new_node->elemData._uint32 = 0;

        if (list->head == NULL)
        {
            list->head = new_node;
        }
        else
        {
            ((Node32_DP_t *)list->tail)->next = new_node;
            new_node->prev = list->tail;
        }

        list->tail = new_node;
    }

    list->size = num;
    return list;
}

static bool _Destory(List *list)
{
    Node32_DP_t *cursor;
    for (int i = 0; i < ((LinkList *)list)->size; i++)
    {
        cursor = (Node32_DP_t *)((LinkList *)list)->head;
        ((LinkList *)list)->head = ((Node32_DP_t *)((LinkList *)list)->head)->next;
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

    Node32_DP_t *node = (Node32_DP_t *)((LinkList *)list)->head;
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
        ((LinkList *)list)->head = (Node32_DP_t *)add_node;
    }
    else
    {
        ((Node32_DP_t *)((LinkList *)list)->tail)->next = (Node32_DP_t *)add_node;
        ((Node32_DP_t *)add_node)->prev = (Node32_DP_t *)((LinkList *)list)->tail;
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

    Node32_DP_t *node = (Node32_DP_t *)((LinkList *)list)->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    if (index == 0)
    {
        node->prev = (Node32_DP_t *)add_node;
        ((Node32_DP_t *)add_node)->next = node;
        ((LinkList *)list)->head = (Node32_DP_t *)add_node;
    }
    else
    {
        ((Node32_DP_t *)add_node)->prev = node->prev;
        ((Node32_DP_t *)add_node)->next = node;
        node->prev->next = (Node32_DP_t *)add_node;
        node->prev = (Node32_DP_t *)add_node;
    }

    return ((LinkList *)list)->size++;
}

static Node *_Remove(List *list)
{
    if (_isEmpty(list))
    {
        return NULL;
    }
    Node32_DP_t *end = ((Node32_DP_t *)((LinkList *)list)->tail)->prev;
    Node32_DP_t *ret = (Node32_DP_t *)((LinkList *)list)->tail;

    end->next = NULL;
    ((LinkList *)list)->tail = end;

    ((LinkList *)list)->size--;
    return ret;
}

static Node *_Delete(List *list, int index)
{
    if (((LinkList *)list)->size < index)
    {
        return NULL;
    }

    Node32_DP_t *node = ((LinkList *)list)->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;

    return node;
}

static void _Show(List *list)
{
}

static void _Sort(List *list, int (*comp)(const void *, const void *))
{
}

const ListAPI _Dlist_api = {
    _Init,
    _Create,
    _Destory,
    _isEmpty,
    _Select,
    _Append,
    _Insert,
    _Remove,
    _Delete,
    _Show,
    _Sort,
};