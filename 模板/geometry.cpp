double EPS = 1e-10;
double add(double a,double b) {
    if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}
struct Point{
    double x, y;
    Point(){}
    Point(double x, double y) :x(x), y(y) {}
    Point operator + (Point p) {
        return Point(add(x, p.x), add(y, p.y));
    }
    Point operator - (Point p) {
        return Point(add(x, -p.x), add(y, -p.y));
    }
    Point operator * (double d) {
        return Point(x*d, y*d);
    }
    double dot(Point p) {    //内积
        return add(x * p.x, y * p.y);
    }
    double det(Point p) {    //外积
        return add(x * p.y, -y * p.x);
    }
};

bool on_seg(Point p1, Point p2, Point q) {      //判断点q是否在线段p1-p2上
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
Point intersection(Point p1, Point p2, Point q1, Point q2) {    //计算直线p1-p2与直接q1-q2的交点
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}