#include "Polygon.hpp"
#include "PolygonAlgorithm.hpp"
#include "PolygonAlgorithmSp.hpp"

#include <iostream>

int main()
{
    // Triangle
    CPolygon<double> t1;
    t1._vecPoints.push_back(CPoint<double>(1,3));
    t1._vecPoints.push_back(CPoint<double>(0,2));
    t1._vecPoints.push_back(CPoint<double>(2,2));

    // Triangle
    CPolygon<double> t2;
    t2._vecPoints.push_back(CPoint<double>(1,1));
    t2._vecPoints.push_back(CPoint<double>(0,2));
    t2._vecPoints.push_back(CPoint<double>(2,2));

    // Triangle
    CPolygon<double> t3;
    t3._vecPoints.push_back(CPoint<double>(1,-5));
    t3._vecPoints.push_back(CPoint<double>(0,2));
    t3._vecPoints.push_back(CPoint<double>(2,2));

    // Triangle
    CPolygon<double> t4;
    t4._vecPoints.push_back(CPoint<double>(-5,-5));
    t4._vecPoints.push_back(CPoint<double>(0,2));
    t4._vecPoints.push_back(CPoint<double>(2,2));

    // Triangle
    CPolygon<double> t5;
    t5._vecPoints.push_back(CPoint<double>(5,-5));
    t5._vecPoints.push_back(CPoint<double>(0,2));
    t5._vecPoints.push_back(CPoint<double>(2,2));

    // Rect
    CPolygon<double> r1;
    r1._vecPoints.push_back(CPoint<double>(0,0));
    r1._vecPoints.push_back(CPoint<double>(0,2));
    r1._vecPoints.push_back(CPoint<double>(2,2));
    r1._vecPoints.push_back(CPoint<double>(2,0));

    //
    ISpTriangleInPolygon i1;
    if(i1.isTriangleInPolygon(t1,r1))
    {
        std::cout<< "Triangle t1 in Rect" <<std::endl;
    }

    if(i1.isTriangleInPolygon(t2,r1))
    {
        std::cout<< "Triangle t2 in Rect" <<std::endl;
    }

    if(i1.isTriangleInPolygon(t3,r1))
    {
        std::cout<< "Triangle t3 in Rect" <<std::endl;
    }
    
    if(i1.isTriangleInPolygon(t4,r1))
    {
        std::cout<< "Triangle t4 in Rect" <<std::endl;
    }

    if(i1.isTriangleInPolygon(t5,r1))
    {
        std::cout<< "Triangle t5 in Rect" <<std::endl;
    }

    getchar();
    
    return 0;
}