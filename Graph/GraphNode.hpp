#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include <vector>
#include <list>
#include <queue>

class CGraphNode
{
public:
    std::vector<CGraphNode *> m_relation;
    void *content;
    int visited;

    CGraphNode()
    {
        visited = 0;
        content = NULL;
    }
    ~CGraphNode() {}

    static std::vector<CGraphNode *> getReference(std::vector<CGraphNode> &src);

    /*
    使用广度优先搜索方式寻找相关节点
    */
    static void visitedByBFS(CGraphNode *node);

    /**/
    static std::vector<std::vector<CGraphNode *>> spiltNodesToSets(std::vector<CGraphNode *> &graph);

    /**/
    template <class T>
    static std::vector<CGraphNode> cvtToGraphNode(std::vector<T> &v_content);

    /**/
    template <class T>
    static std::vector<T *> getOriginType(const std::vector<CGraphNode *> &v_nodes);

    /**/
};

template <class T>
std::vector<CGraphNode> CGraphNode::cvtToGraphNode(std::vector<T> &v_content)
{
    std::vector<CGraphNode> v_nodes;
    for (int i = 0; i < v_content.size(); i++)
    {
        CGraphNode node;
        node.content = &v_content[i];
        v_nodes.push_back(node);
    }
    return v_nodes;
}

template <class T>
std::vector<T *> CGraphNode::getOriginType(const std::vector<CGraphNode *> &v_nodes)
{
    std::vector<T *> v_origin;
    for (int i = 0; i < v_nodes.size(); i++)
    {
        T *ori = (T *)v_nodes[i]->content;
        v_origin.push_back(ori);
    }
    return v_origin;
}

#endif