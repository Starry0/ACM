#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5e4+10;
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
Point ps[N];
int n;
bool cmp(Point x, Point y) {
    if(x.x != y.x) return x.x < y.x;
    else return x.y < y.y;
}
vector<Point> convex_hull(Point *ps, int) {
    sort(ps, ps+n, cmp);
    int k = 0;
    vector<Point> qs(n*2);
    for(int i = 0; i < n; i ++) {   //下侧
        while(k > 1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for(int i = n-2, t = k; i >= 0; i --) { //上侧
        while(k > t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}
double dist(Point p1, Point p2) {
    return (p1-p2).dot(p1-p2);
}
void solve1() {
    vector<Point> qs = convex_hull(ps, n);
    double res = 0;
    for(int i = 0; i < qs.size(); i ++) {
        for(int j = 0; j < i; j ++) {
            res = max(res, dist(qs[i], qs[j]));
        }
    }
    printf("%.0f\n",res);
}
void solve() {
    vector<Point> qs = convex_hull(ps, n);
    int n = qs.size();
    if(n == 2) {
        printf("%.0f\n",dist(qs[0], qs[1]));
        return;
    }
    int i = 0, j = 0;
    for(int k = 0; k < n; k ++) {
        if(!cmp(qs[i], qs[k])) i = k;
        if(cmp(qs[j], qs[k])) j = k;
    }
    double res = 0;
    int si = i, sj = j;
    while(si != j || sj != i) {
        res = max(res, dist(qs[i], qs[j]));
        if((qs[(i+1)%n] - qs[i]).det(qs[(j+1)%n] - qs[j]) < 0) {
            i = (i + 1) % n;
        } else j = (j + 1) % n;
    }
    printf("%.0f\n",res);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%lf %lf", &ps[i].x, &ps[i].y);
    }
    solve();
    return 0;
}
