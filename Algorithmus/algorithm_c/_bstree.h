#include <stdio.h>
#include <stdlib.h>

/*
ref: https://blog.csdn.net/kang___xi/article/details/80392565
*/

/*
todo: https://blog.csdn.net/ns_code/article/details/19823463
*/



// 二叉排序树
typedef struct BSTNode
{
    int data;
    BSTNode* link_child;
    BSTNode* right_child;
}BSTNode, *BSTree;

bool Search(BSTree bst, int key, BSTree f, BSTree *p);

//查找成功时，p指向值为key的节点。如果查找失败，则p指向遍历的最后一个节点
bool Search(BSTree bst, int key, BSTree f, BSTree *p)
{
    if( !bst)
    {
        *p = f;
        return false;
    }

    if( bst->data == key)
    {
        *p = bst;
        return true;
    }
    else if ( bst->data < key)
    {
        return Search(bst->right_child, key, bst, p);    
    }

    return Search(bst->link_child, key, bst, p);
}

void InOderTraverse(BSTree bst)
{
    // 中序递归遍历二叉树
    if( bst != NULL)
    {
        InOderTraverse(bst->link_child);
        printf("%d ", bst->data);
        InOderTraverse(bst->right_child);
    }
}

static BSTNode* BuyNode(int data)
{
    // 生成一个节点
    BSTNode* ptmp = (BSTNode*)malloc(sizeof(BSTNode));
    if(ptmp == NULL)
    {
        return ptmp;
    }

    ptmp->data = data;
    ptmp->link_child = NULL;
    ptmp->right_child = NULL;

    return ptmp;
}


bool Insert(BSTree *bst, int key)
{
    if(*bst == NULL)
    {
        // 空树
        *bst = BuyNode(key);    // 插入空节点
        return true;
    }

    BSTNode *p;
    // 先在 二叉排序树中 查找要插入的值 是否已经存在
    if( !Search(*bst, key, NULL, &p))   // 如果查找失败，则插入; 此时 p指向遍历的最后一个节点
    {
        BSTNode* pNew = BuyNode(key);
        if(key < p->data)
        {
            p->link_child = pNew;
        }
        else if(key > p->data)
        {
            p->right_child = pNew;
        }

        return true;
    }
    else
    {
        printf("\nThe node(%d) already exists.\n", key);
    }

    return false;
}


BSTNode* FindParent(BSTree bst, BSTNode* child)
{
    if( bst == NULL)
    {
        return NULL;
    }

    if( bst->link_child == child || bst->right_child == child)
    {
        return bst;
    }
    else if( bst->link_child != NULL)
    {
        FindParent(bst->link_child, child);
    }
    else if( bst->right_child != NULL)
    {
        FindParent(bst->right_child, child);
    }
}

/*
删除分三种情况：
(1)被删除的节点无孩子，说明该节点是叶子节点，直接删
(2)被删除的节点只有左孩子或者右孩子，直接删，并将其左孩子或者右孩子放在被删节点的位置
(3)被删除的节点既有右孩子又有右孩子
*/
void Delete(BSTree *bst, int key)
{
    if( *bst == NULL)
    {
        return ; // 空树直接报错
    }

    BSTNode* p;
    BSTNode* f = NULL;
    BSTNode* q, *s;
    if(Search(*bst, key, NULL, &p)) // 确认存在值为key的节点， 则p指向该节点
    {
        if(p->link_child == NULL || p->right_child != NULL) // 无左孩子，则有右孩子
        {
            q = p->right_child;
            p->data = q->data;
            p->right_child = q->right_child;
            p->link_child = q->link_child;
            free(q);
        }
        else if(p->right_child == NULL && p->link_child !=NULL) // 无右孩子，有左孩子
        {
            q = p->link_child;
            p->data = q->data;
            p->right_child = q->right_child;
            p->link_child = q->link_child;
            free(q);
        }
        else if (p->right_child != NULL && p->link_child != NULL) // 既有左孩子，又有右孩子
        {
            q = p;
            s = p->link_child; // 找左孩子的最右孩子
            while ( s->right_child)
            {
                q  = s;
                s = s->right_child;
            }
            p->data = s->data;

            if( q != p)
            {
                q->right_child = p->link_child;
            }
            else
            {
                q->link_child = s->link_child;
            }
            free(s);
        }
        else
        {
            if( *bst == p)  // 只有一个根节点
            {
                free(*bst);
                *bst = NULL;
                return ;
            }

            BSTNode* parent = FindParent(*bst, p);
            if( parent->link_child == p)
            {
                parent->link_child = NULL;
            }
            else
            {
                parent->right_child = NULL;
            }
            free(p);
        }
    }
}











