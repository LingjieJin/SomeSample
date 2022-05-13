#include "Polygon.hpp"

#include <iostream>

int main()

{
    CPoint<double> p1(5,5);
    CPoint<double> p2(3,3);

    CPoint<double> p3;
    std::cout << "Init P3:" << p3._x << p3._y <<std::endl;
    p3 = p1 - p2;

    std::cout << "P1:" << p1._x << p1._y <<std::endl;
    std::cout << "P2:" << p2._x << p2._y <<std::endl;
    std::cout << "P3:" << p3._x << p3._y <<std::endl;

    return 0;
}