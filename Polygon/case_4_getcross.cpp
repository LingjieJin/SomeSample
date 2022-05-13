#include "Polygon.hpp"
#include "PolygonAlgorithm.hpp"


int main()
{
    CLine<int> l1(0, 0, 9, 9);
	CLine<int> l2(3, 3, 3, 0);
    CPoint<int> p;
    int a1, b1;

    IPolygonAlgorithmBase<int> a;


    if (a.isLineIntersect(l1, l2))
	{
		a.GetCrossPoint(l1._p1, l1._p2, l2._p1, l2._p2, a1,b1);
		std::cout << "a:line is intersect" << std::endl;
		std::cout << p._x << ", " << p._y << std::endl;
	}

    return 0;   
}