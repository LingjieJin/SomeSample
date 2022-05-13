#ifndef __TREENODE_HPP__
#define __TREENODE_HPP__

#include <iostream>
#include <vector>

typedef struct Node
{
    double dData;
    Node_t leftNode;
    Node_t rightNode;
    //显示树节点信息
    void showNode()
    {
        std::cout << dData << std::endl;
    }
} Node_t;

class CBiTree
{
public:
    //
    Node_t* root;
public:
    CBiTree() {
        root = NULL;
    }
    ~CBiTree() {
        // 遍历删除
    }
    //
    CBiTree(double arr[], int length)
    {
        
    }

    //
    void insertNode(double data)
    {

    }
    //
};

#endif