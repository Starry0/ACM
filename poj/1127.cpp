#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
const int N = 20;
const int M = 110;
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
int n;
Point p[N], q[N];
int m;
bool g[N][N];
void solve() {
    for(int i = 1; i <= n; i ++) {
        g[i][i] = true;
        for(int j = 1; j < i; j ++) {
            if((p[i] - q[i]).det(p[j] - q[j]) == 0) {
                g[i][j] = g[j][i] = on_seg(p[i], q[i], q[j])
                                    || on_seg(p[i], q[i], p[j])
                                    || on_seg(p[j], q[j], q[i])
                                    || on_seg(p[j], q[j], p[i]);
            } else {
                Point r = intersection(p[i], q[i], p[j], q[j]);
                g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
            }
        }
    }
    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }
}
int main() {
    while(cin >> n && n) {
        memset(g, false, sizeof(g));
        for(int i = 1; i <= n; i ++) {
            cin >> p[i].x >> p[i].y >> q[i].x >> q[i].y;
        }
        int a, b;
        solve();
        while(cin >> a >> b && (a+b)) {
            if(g[a][b]) printf("CONNECTED\n");
            else printf("NOT CONNECTED\n");
        }
    }
    return 0;
}
