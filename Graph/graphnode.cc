#include <iostream>
#include <vector>
#include <list>
#include <queue>

template <class T>
class CPoint
{
public:
    T _x;
    T _y;

    CPoint()
    {
        _x = 0;
        _y = 0;
    }

    CPoint(T x, T y)
    {
        _x = x;
        _y = y;
    }

    CPoint(const CPoint<T> &p)
    {
        _x = p._x;
        _y = p._y;
    }

    CPoint<T> operator+(const CPoint<T> &p)
    {
        CPoint<T> temp;
        temp._x = this->_x + p._x;
        temp._y = this->_y + p._y;
        return temp;
    }

    CPoint<T> operator-(const CPoint<T> &p)
    {
        CPoint<T> temp;
        temp._x = this->_x - p._x;
        temp._y = this->_y - p._y;
        return temp;
    }

    friend CPoint<T> operator+(const CPoint<T> &p1, const CPoint<T> &p2)
    {
        CPoint<T> temp;
        temp._x = p1._x + p2._x;
        temp._y = p1._y + p2._y;
        return temp;
    }

    CPoint<T> &operator+=(const CPoint<T> &p)
    {
        this->_x += p._x;
        this->_y += p._y;

        return this;
    }

    bool operator==(const CPoint<T> &point) const
    {
        return ((fabs(_x - point._x) < 1e-8) && (fabs(_y - point._y) < 1e-8));
    }

    bool operator<(const CPoint<T> &point) const
    {
        return (_x < point._x);
    }

    ~CPoint() {}

    std::string ToString()
    {
        std::ostringstream ret;

        ret << "X:" << _x << " ,Y:" << _y << " ";

        return ret.str();
    }
};


typedef struct dataNode
{
    // pointer to src content
    void *content;
    // visited symbol
    int visited;
}dataNode_t;

class CGraphNode
{
public:
    std::vector<dataNode_t> m_relation;
    
    CGraphNode()
    {
    }
    ~CGraphNode() {}

    /*
    获取数据源
    */
    template <class T>
    static std::vector<dataNode_t> getSrcData(std::vector<T> &v_content)
    {
        m_relation.clear();

        for (int i = 0; i < v_content.size(); i++)
        {
            dataNode_t node;
            node.content = &v_content[i];
            node.visited = 0;
            m_relation.push_back(node);
        }
        return m_relation;
    }

    // static std::vector<CGraphNode *> getReference(std::vector<CGraphNode> &src)
    // {
    //     std::vector<CGraphNode *> ref;

    //     for (int i = 0; i < src.size(); i++)
    //     {
    //         ref.push_back(&src[i]);
    //     }
    //     return ref;
    // }

    /*
    使用广度优先搜索方式寻找相关节点
    */
    void visitedByBFS()
    {
        dataNode_t* firstNode = &m_relation.front();

        std::queue<dataNode_t *> help_que;
        help_que.push(firstNode);
        firstNode->visited = 1;

        while (!help_que.empty())
        {
            dataNode_t *front = help_que.front();

            std::cout << "Need to visit %ld elements\n"
                      << m_relation.size() << std::endl;

            for (int i = 0; i < m_relation.size(); i++)
            {
                if (m_relation[i].visited == 0)
                {
                    m_relation[i].visited = 1;
                    help_que.push(&m_relation[i]);
                }
            }
            help_que.pop();
        }
    }

    /*
     */
    static std::vector<std::vector<CGraphNode *>> spiltNodesToSets(std::vector<CGraphNode *> &graph);

    

    /**/
    template <class T>
    static std::vector<T *> getOriginType(const std::vector<CGraphNode *> &v_nodes)
    {
        std::vector<T *> v_origin;
        for (int i = 0; i < v_nodes.size(); i++)
        {
            T *ori = (T *)v_nodes[i]->content;
            v_origin.push_back(ori);
        }
        return v_origin;
    }

    /**/
};

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
        std::cout << "visited copy...\n"
                  << std::endl;
        visitedByBFS(front);
        std::cout << "visited copy end...\n"
                  << std::endl;

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
                std::cout << "src size:%ld, copy size:%ld, set size:%ld\n"
                          << graph.size() << copy.size() << set.size() << std::endl;
            }
            else
            {
                it++;
            }
        }
        sets.push_back(set);
    }
    std::cout << "Sets size:%ld\n"
              << sets.size() << std::endl;

    return sets;
}

int main()
{
    // example data
    std::vector<CPoint<double>> v_points;
    CPoint<double> p1 = CPoint<double>(0.0, 0.0);
    CPoint<double> p2 = CPoint<double>(5.0, 5.0);
    CPoint<double> p3 = CPoint<double>(8.0, 8.0);
    CPoint<double> p4 = CPoint<double>(9.999, 9.0999);
    v_points.push_back(p1);
    v_points.push_back(p2);
    v_points.push_back(p3);
    v_points.push_back(p4);

    CGraphNode a;
    std::vector<CGraphNode> v_nodes = CGraphNode::cvtToGraphNode(v_points);
    v_nodes[0].m_relation.push_back(&v_nodes[1]);
    v_nodes[0].m_relation.push_back(&v_nodes[3]);
    v_nodes[1].m_relation.push_back(&v_nodes[3]);

    std::vector<CGraphNode *> graps = CGraphNode::getReference(v_nodes);

    printf("start spilt....\n");

    std::vector<std::vector<CGraphNode *>> sets;
    sets = CGraphNode::spiltNodesToSets(graps);

    printf("get sets size: %ld.\n", sets.size());

    for (int i = 0; i < sets.size(); i++)
    {
        std::vector<CPoint<double> *> v_ori;
        v_ori = CGraphNode::getOriginType(sets[i]);
        for (int j = 0; j < v_ori.size(); j++)
        {
            printf("%s\n", v_ori[j]->ToString().c_str());
        }
    }

    return 0;
}