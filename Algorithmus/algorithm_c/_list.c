#include "_list.h"

/* Appends a node to a list */
void list_append_node(list* in_list, node* in_node)
{
    in_node->next = NULL;

    if ( in_list->head )
    {
        in_list->tail->next = in_node;
        in_list->tail = in_node;
    }
    else
    {
        // 第一次加入节点
        in_list->head = in_list->tail = in_node;
    }
    
    in_list->size ++;
}

/* Removes the first node from a list and returns it */
node* list_remove_head(list* in_list)
{
    node* node = NULL;
    node->next = NULL;

    // 链表非空
    if( in_list->head)
    {
        node = in_list->head;
        in_list->head = in_list->head->next;
        // 
        if (in_list->head == NULL)
        {
            in_list->tail = NULL;
        }
    }
    
    return node;
}

/* Removes all nodes but for list itself */
void list_remove_all(list *in_list, pfcb_list_node_free pf)
{
    node* node;
    while ( node = list_remove_head(in_list))
    {
        if (pf)
        {
            (*pf)(node);
        }
        free(node);
    }
}

/* Returns a copy of a list_t from heap */
list* list_copy(list in_list)
{
    list* new_list = (list*)malloc(sizeof(list));
    *new_list = in_list;

    return new_list;
}

/* Concatenates two lists into first list */
void list_concat(list* first, list* second)
{
    if(first->head)
    {
        if (second->head)
        {
            first->tail->next = second->head;
            first->tail = second->tail;
        }
        
    }
    else
    {
        *first = *second;
    }
    second->head = second->tail = NULL;

    first->size += second->size;    
}


/* Allocates a new listnode_t from heap */
node* list_node_create(void* data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = data;

    return new_node;
}

node* list_key_create(long key)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->key = key;

    return new_node;
}

/* Allocates a empty list_t from heap */
list* list_create()
{
    list* new_list = (list*)malloc(sizeof(list));
    new_list->size = 0;
    new_list->head = new_list->tail = NULL;
    
    return new_list;
}

/* Frees a empty list_t from heap */
void list_destroy(list* in_list, pfcb_list_node_free pf)
{
    list_remove_all(in_list, pf);
    free(in_list);
}

/* Gets count of nodes in the list */
size_t list_size(const list* in_list)
{
    return in_list->size;
}

/* Gets node by index 0-based. 0 is head */
node* list_node_at(const list* in_list, int index)
{
    int i = 0;
    node* node = in_list->head;

    while (i < index)
    {
        node = node->next;
        i++;
    }

    return node;
}




