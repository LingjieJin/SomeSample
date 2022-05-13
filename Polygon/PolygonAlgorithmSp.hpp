#include "PolygonAlgorithm.hpp"

/**
 * 针对不考虑点在边缘的情况下做判断
 */

template <class T>
class ISpPolygonAlgorithm : public IPolygonAlgorithmBase<T>
{
public:
    ISpPolygonAlgorithm<T>() {}
    ~ISpPolygonAlgorithm<T>() {}

    /**
     * 判断点是否在矩形内
     * 不包括矩形边上
     */
    bool isPointInRect(T x, T y, CRect<T> &rect)
    {
        if (x > rect.p_min._x && x < rect.p_max._x && y > rect.p_min._y && y < rect.p_max._y)
            return true;
        return false;
    }

    /**
     * 判断点是否在多边形内
     * 不包括多边形边上
     */
    bool isPointInPolygon(T x, T y, const CPolygon<T> &p)
    {
        bool isInside = false;
        int count = 0;

        // quickly check
        CRect<T> r = IPolygonAlgorithmBase<T>::getPolygonEnvelopRect(p);
        if (!isPointInRect(x, y, r))
        {
            return false;
        }

        //
        double minX = 1.7976931348623158e+308; // double max value
        for (int j = 0; j < p._vecPoints.size(); j++)
        {
            minX = MIN(minX, p._vecPoints[j]._x);
        }

        // judge point
        double px = x;
        double py = y;
        // line start point
        double linePoint1x = x;
        double linePoint1y = y;
        // line end point
        double linePoint2x = minX - 10; //取最小的X值还小的值作为射线的终点
        double linePoint2y = y;

        //遍历每一条边
        for (int i = 0; i < p._vecPoints.size(); i++)
        {
            double cx1 = p._vecPoints[i]._x;
            double cy1 = p._vecPoints[i]._y;
            double cx2 = p._vecPoints[(i + 1) % p._vecPoints.size()]._x;
            double cy2 = p._vecPoints[(i + 1) % p._vecPoints.size()]._y;

            if (IPolygonAlgorithmBase<T>::isPointOnLine(px, py, cx1, cy1, cx2, cy2))
            {
                return false;
            }

            if (fabs(cy2 - cy1) < 0.000001) //平行则不相交
            {
                continue;
            }

            if (IPolygonAlgorithmBase<T>::isPointOnLine(cx1, cy1, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
            {
                if (cy1 > cy2) //只保证上端点+1
                {
                    count++;
                }
            }
            else if (IPolygonAlgorithmBase<T>::isPointOnLine(cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
            {
                if (cy2 > cy1) //只保证上端点+1
                {
                    count++;
                }
            }
            else if (isLineIntersect(cx1, cy1, cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y)) //已经排除平行的情况
            {
                count++;
            }
        }

        if (count % 2 == 1)
        {
            isInside = true;
        }

        return isInside;
    }

    /**
     * 判断线段是否相交
     * 如果线段交于一点
     * 不算相交
     */
    bool isLineIntersect(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4)
    {
        /**
         * 快速排斥：
         * 两个线段为对角线组成的矩形
         * 如果这两个矩形没有重叠的部分，那么两条线段是不可能出现重叠的
        */
        if (!(MIN(x1, x2) < MAX(x3, x4) && MIN(y3, y4) < MAX(y1, y2) && MIN(x3, x4) < MAX(x1, x2) && MIN(y1, y2) < MAX(y3, y4))) //这里的确如此，这一步是判定两矩形是否相交
            /**
             * 1.线段ab的低点低于cd的最高点（可能重合）
             * 2.cd的最左端小于ab的最右端（可能重合）
             * 3.cd的最低点低于ab的最高点（加上条件1，两线段在竖直方向上重合）
             * 4.ab的最左端小于cd的最右端（加上条件2，两直线在水平方向上重合）
             * 综上4个条件，两条线段组成的矩形是重合的
             * 特别要注意一个矩形含于另一个矩形之内的情况
             */
            return false;
        /**
         * 跨立实验：
         * 如果两条线段相交，那么必须跨立，就是以一条线段为标准，另一条线段的两端点一定在这条线段的两段
         * 也就是说a b两点在线段cd的两端，c d两点在线段ab的两端
        */
        double u, v, w, z; //分别记录两个向量
        u = (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
        v = (x4 - x1) * (y2 - y1) - (x2 - x1) * (y4 - y1);
        w = (x1 - x3) * (y4 - y3) - (x4 - x3) * (y1 - y3);
        z = (x2 - x3) * (y4 - y3) - (x4 - x3) * (y2 - y3);
        return (u * v <= 0.00000001 && w * z <= 0.00000001);
    }

    /**
     * 判断线段是否相交
     */
    bool isLineIntersect(const CPoint<T> &p1, const CPoint<T> &p2, const CPoint<T> &p3, const CPoint<T> &p4)
    {
        return isLineIntersect(p1._x, p1._y,
                               p2._x, p2._y,
                               p3._x, p3._y,
                               p4._x, p4._y);
    }

    /**
     * 判断线段是否相交
     */
    bool isLineIntersect(const CLine<T> &line_1, const CLine<T> &line_2)
    {
        return isLineIntersect(line_1._p1._x, line_1._p1._y,
                               line_1._p2._x, line_1._p2._y,
                               line_2._p1._x, line_2._p1._y,
                               line_2._p2._x, line_2._p2._y);
    }

    /**
     * 判断多边形是否相交
     */
    bool isPolygonsIntersect(const CPolygon<T> &p1, const CPolygon<T> &p2)
    {
        int i, j;
        // 1. point judge
        for (i = 0; i < p1._vecPoints.size(); i++)
        {
            if (isPointInPolygon(p1._vecPoints[i]._x, p1._vecPoints[i]._y, p2))
                return true;
        }

        for (i = 0; i < p2._vecPoints.size(); i++)
        {
            if (isPointInPolygon(p2._vecPoints[i]._x, p2._vecPoints[i]._y, p1))
                return true;
        }

        // 2. line judge
        for (i = 0; i < p1._vecPoints.size(); i++)
        {
            for (j = 0; j < p2._vecPoints.size(); j++)
            {
                if (isLineIntersect(p1._vecPoints[i], p1._vecPoints[(i + 1) % p1._vecPoints.size()],
                                    p2._vecPoints[j], p2._vecPoints[(j + 1) % p2._vecPoints.size()]))
                {
                    return true;
                }
            }
        }
        return false;
    }
};


class ISpTriangleInPolygon : public ISpPolygonAlgorithm<double>
{
public:
    ISpTriangleInPolygon() {}
    ~ISpTriangleInPolygon() {}

    /**
     * 判断三角形是否与多边形相交
     */
    bool isTriangleInPolygon(const CPolygon<double> &t, const CPolygon<double> &p)
    {
        int i, j;

        // 不是三角形
        if (t._vecPoints.size() > 3)
            return false;

        // 判断三角形是否和多边形有共同点
        int cout = 0;
        for (i = 0; i < t._vecPoints.size(); i++)
        {
            for (j = 0; j < p._vecPoints.size(); j++)
            {
                if (t._vecPoints[i]._x == p._vecPoints[j]._x && t._vecPoints[i]._y == p._vecPoints[j]._y)
                    cout++;
            }
        }
        // 如果三个顶点都在多边形上 必然相交
        if (cout == 3)
        {
            return true;
        }
        // 三角形和多边形共边
        // 判断点是否在多边形内
        if (cout == 2)
        {
            for (i = 0; i < t._vecPoints.size(); i++)
            {
                // 点在多边形里面 相交
                if (isPointInPolygon(t._vecPoints[i]._x, t._vecPoints[i]._y, p))
                    return true;
            }
            // 点不在多边形内 判断动点线段是否相交
            for (i = 0; i < p._vecPoints.size(); i++)
            {
                if (isLineIntersect(t._vecPoints[0], t._vecPoints[1],
                                    p._vecPoints[i], p._vecPoints[(i + 1) % p._vecPoints.size()]))
                    return true;
            }
            // 另外一条边
            for (i = 0; i < p._vecPoints.size(); i++)
            {
                if (isLineIntersect(t._vecPoints[0], t._vecPoints[2],
                                    p._vecPoints[i], p._vecPoints[(i + 1) % p._vecPoints.size()]))
                    return true;
            }

            // 如果三角形共边 但是点不在多边形内 且动点线段和多边形没有相交
            // 则三角形和多边形不相交
            return false;
        }

        // 正常判断
        return isPolygonsIntersect(t, p);
    }
};