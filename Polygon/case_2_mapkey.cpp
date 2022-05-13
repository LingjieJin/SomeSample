#include "Polygon.hpp"

#include <map>
#include <iostream>

int main()
{
    CPoint<double> a();

    std::map<CPoint<double>, int> test;
    test.insert(std::pair<CPoint<double>, int>(CPoint<double>(46010.593750000000 , 357217.96875000000), 1));
    test.insert(std::pair<CPoint<double>, int>(CPoint<double>(46035.300781250000, 357169.65625000000), 2));


    std::map<CPoint<double>, int>::iterator it = test.find(CPoint<double>(46010.593750000000, 357217.96875000000));
    if (it != test.end())
    {
        std::cout << "find point"<< it->second << std::endl;
    }
    else
    {
        std::cout << "cant find" << std::endl;
    }

    it = test.find(CPoint<double>(46035.300781250000, 357169.65625000000));
    if (it != test.end())
    {
        std::cout << "find point"<< it->second << std::endl;
    }
    else
    {
        std::cout << "cant find" << std::endl;
    }

    return 0;
}