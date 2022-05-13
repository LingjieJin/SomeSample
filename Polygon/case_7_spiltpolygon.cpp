#include "Polygon.hpp"
#include "PolygonAlgorithm.hpp"

#include <iostream>

int main()
{

    CPolygon<double> p1;
    p1._vecPoints.push_back(CPoint<double>(0.0, 0.0));
    p1._vecPoints.push_back(CPoint<double>(3.0, 0.0));
    p1._vecPoints.push_back(CPoint<double>(3.0, 3.0));
    p1._vecPoints.push_back(CPoint<double>(0.0, 3.0));

    CLongLine<double> l1;
    l1.v_points.push_back(CPoint<double>(2.0, 4.0));
    l1.v_points.push_back(CPoint<double>(2.0, 1.0));
    l1.v_points.push_back(CPoint<double>(2.0, -1.0));

    std::vector<CPoint<double>> r1;
    std::vector<CPoint<double>> r2;

    IPolygonAlgorithmBase<double> a;
    a.spiltPolygon(l1, p1, r1, r2);

    for (int  i = 0; i < r1.size(); i++)
    {
        std::cout<< i <<", X:" << r1[i]._x << ", Y:" << r1[i]._y << std::endl;
    }

    for (int  i = 0; i < r2.size(); i++)
    {
        std::cout<< i <<", X:" << r2[i]._x << ", Y:" << r2[i]._y << std::endl;
    }
    

    return 0;
}