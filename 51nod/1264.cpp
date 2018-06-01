/*
  (a-c)×(d-c)*(d-c)×(b-c)>=0&&(c-a)×(b-a)*(b-a)×(d-a)>= 0就可以判断ab,cd相交
   p1×p2 = x1y2 - x2y1 = - p2×p1-----（叉乘公式）叉积
*/
#include <iostream>
#include <stdio.h>
using namespace std;
struct Point{
    double x,y;
};

bool mp(Point a, Point b, Point c, Point d){
    double C = (a.x-c.x)*(d.y-c.y)-(d.x-c.x)*(a.y-c.y);
    double D = (d.x-c.x)*(b.y-c.y)-(b.x-c.x)*(d.y-c.y);
    if(C*D < 0) return false;
    else return true;
}

bool check(Point a, Point b, Point c, Point d){
    if(!mp(a,b,c,d)) return false;
    if(!mp(c,d,a,b)) return false;
    return true;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        Point a, b, c, d;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        if(check(a,b,c,d))cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
