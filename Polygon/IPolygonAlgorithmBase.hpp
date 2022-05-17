template <class T>
class IPolygonAlgorithmBase
{
public:
    virtual ~IPolygonAlgorithmBase() {}

    /* 获取两点之间的距离 */
    T getDistance(const CPoint<T> &p1,const CPoint<T> &p2);


    /*判断点是否在线段上*/
    virtual bool isPointOnLine(T p0_x, T p0_y, T p1_x, T p1_y, T p2_x, T p2_y);
    /*判断点是否在线段上*/
    virtual bool isPointOnLine(T p0_x, T p0_y, CLine<T> &line);
    /*判断点是否在线段上*/
    virtual bool isPointOnLine(CPoint<T> &point, CLine<T> &line);

    /*判断点是否在矩形内 包括矩形边上*/
    virtual bool isPointInRect(const T &x, const T &y, const CRect<T> &rect);
    /*判断点是否在矩形内 包括矩形边上*/
    virtual bool isPointInRect(const CPoint<T> &point, const CRect<T> &rect);

    /*判断点是否在多边形内 包括多边形边上 */
    virtual bool isPointInPolygon(const T &x, const T &y, const CPolygon<T> &polygon);
    /*判断点是否在多边形内 包括多边形边上 */
    virtual bool isPointInPolygon(const CPoint<T> &point, const CPolygon<T> &polygon);

    /*判断线段是否相交 如果线段交于一点 也是相交*/
    virtual bool isLineIntersect(T x1, T y1,
                                 T x2, T y2,
                                 T x3, T y3,
                                 T x4, T y4);
    /*判断线段是否相交 如果线段交于一点 也是相交*/
    virtual bool isLineIntersect(const CPoint<T> &p1,
                                 const CPoint<T> &p2,
                                 const CPoint<T> &p3,
                                 const CPoint<T> &p4);
    /*判断线段是否相交 如果线段交于一点 也是相交*/
    virtual bool isLineIntersect(const CLine<T> &l1, const CLine<T> &l2);

    /*求线段P1P2与Q1Q2的交点*/
    virtual void GetCrossPoint(const CPoint<T> &p1,
                               const CPoint<T> &p2,
                               const CPoint<T> &q1,
                               const CPoint<T> &q2,
                               T &x, T &y);
    /*求线段P1P2与Q1Q2的交点*/
    virtual void GetCrossPoint(const CPoint<T> &p1,
                               const CPoint<T> &p2,
                               const CPoint<T> &q1,
                               const CPoint<T> &q2,
                               CPoint<T> &pCross);
    /*求线段P1P2与Q1Q2的交点*/
    virtual void GetCrossPoint(const CLine<T> &l1,
                               const CLine<T> &l2,
                               CPoint<T> &point);

    /* 判断多边形是否相交 */
    virtual bool isPolygonsIntersect(const CPolygon<T> &p1, const CPolygon<T> &p2);

    /* 获取多边形的最大正矩形 */
    virtual CRect<T> getPolygonEnvelopRect(const CPolygon<T> &p);

    /* 使用线段划分多边形 */
    virtual void spiltPolygon(const CLongLine<T> &line,
                              const CPolygon<T> &polygon,
                              std::vector<CPoint<T>> &result_1,
                              std::vector<CPoint<T>> &result_2);

    /** 计算多边形面积 
     * Shoelace formula 计算面积
     * 不管坐标原点怎样选取，只要顺序输入多边形每个顶点的坐标，按同样的顺序（顺时针或反时针）两两叉乘
     * 这些叉乘的和的绝对值的一半就是该多边形面积。
     */
    virtual double calPolygonArea(std::vector<CPoint<T>> &polygon);
};