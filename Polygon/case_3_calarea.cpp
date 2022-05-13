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

    CPolygon<double> p2;
    p2._vecPoints.push_back(CPoint<double>(0.0, 0.0));
    p2._vecPoints.push_back(CPoint<double>(2.0, 0.0));
    p2._vecPoints.push_back(CPoint<double>(3.0, 1.0));
    p2._vecPoints.push_back(CPoint<double>(3.0, 2.0));
    p2._vecPoints.push_back(CPoint<double>(0.0, 2.0));

    IPolygonAlgorithmBase<double> a;
    double area_1 = a.calPolygonArea(p1._vecPoints);

    double area_2 = a.calPolygonArea(p2._vecPoints);

    std::cout << "area1:" << area_1 <<std::endl;
    std::cout << "area2:" << area_2 <<std::endl;

    return 0;
}