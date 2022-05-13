#ifndef CPOLYGON_HPP
#define CPOLYGON_HPP

#include <sstream>
#include <vector>
#include <cmath>

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

    CPoint<T>& operator+=(const CPoint<T> &p)
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

template <class T>
class CLine
{
public:
    CPoint<T> _p1;
    CPoint<T> _p2;

    CLine<T>()
    {
        _p1._x = 0;
        _p1._y = 0;
        _p2._x = 0;
        _p2._y = 0;
    }

    CLine<T>(T x1, T y1, T x2, T y2)
    {
        _p1._x = x1;
        _p1._y = y1;
        _p2._x = x2;
        _p2._y = y2;
    }

    CLine<T>(const CPoint<T> &p1, const CPoint<T> &p2)
    {
        _p1._x = p1._x;
        _p1._y = p1._y;
        _p2._x = p2._x;
        _p2._y = p2._y;
    }

    ~CLine() {}
};

template <class T>
class CLongLine
{
public:
    std::vector<CPoint<T>> v_points;

    CLongLine()
    {
    }

    ~CLongLine() {}
};

template <class T>
class CTriangle
{
public:
    CPoint<T> _p1;
    CPoint<T> _p2;
    CPoint<T> _p3;

    CTriangle();
};

template <class T>
class CRect
{
public:
    CPoint<T> p_min, p_max;

    CRect()
    {
        p_min = CPoint<double>(0.0, 0.0);
        p_max = CPoint<double>(0.0, 0.0);
    }

    CRect(T pmin_x, T pmin_y, T pmax_x, T pmax_y)
    {
        p_min = CPoint<T>(pmin_x, pmin_y);
        p_max = CPoint<T>(pmax_x, pmax_y);
    }

    CRect(CPoint<T> &pmin, CPoint<T> &pmax)
    {
        p_min = CPoint<T>(pmin);
        p_max = CPoint<T>(pmax);
    }

    CRect(const CRect &rect)
    {
        p_min = rect.p_min;
        p_max = rect.p_max;
    }

    CRect &operator=(const CRect &rect)
    {
        p_min = rect.p_min;
        p_max = rect.p_max;
    }
};

template <class T>
class CPolygon
{
public:
    std::vector<CPoint<T>> _vecPoints;

    CPolygon() {}

    CPolygon(std::vector<CPoint<T>> &points)
    {
        _vecPoints = std::vector<CPoint<T>>(points);
    }

    CPolygon(CPolygon &polygon)
    {
        _vecPoints = std::vector<CPoint<T>>(polygon._vecPoints);
    }

    ~CPolygon() {}
};

#endif
