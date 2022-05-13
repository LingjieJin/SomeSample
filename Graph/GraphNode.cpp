#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"
#include "../Log/Debug.h"

#include <stdio.h>

std::vector<CGraphNode *> CGraphNode::getReference(std::vector<CGraphNode> &src)
{
    std::vector<CGraphNode *> ref;
   
    for (int i = 0; i < src.size(); i++)
    {
        ref.push_back(&src[i]);
    }
    return ref;
}

void CGraphNode::visitedByBFS(CGraphNode *node)
{
    std::queue<CGraphNode *> help_que;
    help_que.push(node);
    node->visited = 1;

    while (!help_que.empty())
    {
        CGraphNode *front = help_que.front();

        DPRINTF("Need to visit %ld elements\n", front->m_relation.size());

        for (int i = 0; i < front->m_relation.size(); i++)
        {
            if (front->m_relation[i]->visited == 0)
            {
                front->m_relation[i]->visited = 1;
                help_que.push(front->m_relation[i]);
            }
        }
        help_que.pop();
    }
}

std::vector<std::vector<CGraphNode *>> CGraphNode::spiltNodesToSets(std::vector<CGraphNode *> &graph)
{
    // sets
    std::vector<std::vector<CGraphNode *>> sets;

    // copy elements
    std::vector<CGraphNode *>
        copy = graph;

    while (!copy.empty())
    {
        std::vector<CGraphNode *> set;

        CGraphNode *front = copy.front();
        DPRINTF("visited copy...\n");
        visitedByBFS(front);
        DPRINTF("visited copy end...\n");

        // 遍历copy中的所有元素
        // 查看是否被访问过
        // 如果访问过，证明是在同一个集合中，保存，放入输出MultiSet中
        // 同时删除copy中的元素，进行下一次操作
        for (std::vector<CGraphNode *>::iterator it = copy.begin();
             it != copy.end();)
        {
            if ((*it)->visited == 1)
            {
                set.push_back(*it);
                copy.erase(it);
                DPRINTF("src size:%ld, copy size:%ld, set size:%ld\n", graph.size(), copy.size(), set.size());
            }
            else
            {
                it++;
            }
        }
        sets.push_back(set);
    }
    DPRINTF("Sets size:%ld\n", sets.size());

    return sets;
}