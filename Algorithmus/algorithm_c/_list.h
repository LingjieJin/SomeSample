#ifndef LIST_H
#define LIST_H

#include "_unistd.h"

typedef struct node
{
    struct node *next;
    union 
    {
        void* data;
        struct list* list;
        const char* str;
        long key;
    };
}node;


typedef struct list
{
    size_t size;
    node* head;
    node* tail;
}list, *p_list;


/* A prototype of callbacked function called by list_destroy(), NULL for no use. */
typedef void(*pfcb_list_node_free)(node* node);    

/* An example of free node data function implemented by callee:
void my_list_node_free(listnode_t *node)
{
    free(node->data);
}
*/

/* Appends a node to a list */
extern void list_append_node(list* in_list, node* in_node);

/* Removes the first node from a list and returns it */
extern node* list_remove_head(list* in_list);

/* Removes all nodes but for list itself */
extern void list_remove_all(list*in_list, pfcb_list_node_free pfunc /* NULL for no use or a key node */);

/* Returns a copy of a listfrom heap */
extern list* list_copy(list in_list);

/* Concatenates two lists into first list. NOT freeing the second */
extern void list_concat(list* first, list* second);

/* Allocates a newnodefrom heap. NO memory allocated for input node_data */
extern node* list_node_create(void* node_data);

/* Allocates a newnodewith a key node type */
extern node* list_key_create(long node_key);

/* Allocates a empty listfrom heap */
extern list* list_create();

/* Frees in_list's all nodes and destroys in_list from heap.
 * the callee is responsible for freeing node data.
 * the node freed-function(pfunc) is called by list_destroy.
 */
extern void list_destroy(list*in_list, pfcb_list_node_free pfunc /* NULL for no use or a key node */);

/* Gets count of nodes in the list */
extern size_t list_size(const list* in_list);

/* Gets node by index 0-based. 0 is head */
extern node* list_node_at(const list* in_list, int index);




#endif