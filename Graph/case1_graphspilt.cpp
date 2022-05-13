#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"

#include <stdio.h>

int main()
{
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