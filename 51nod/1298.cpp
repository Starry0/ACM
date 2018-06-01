/*
已知两点坐标，求ax + by + c = 0;
ax1 + by1 + c = 0;
ax2 + by2 + c = 0;
即 b(y1-y2) = a(x2-x1)
*/
#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
struct Point{
    ll x,y;
};
Point a, b, c;
ll xc, yc, r;
ll distance(Point *p1) {
    return (p1->x-xc)*(p1->x-xc)+(p1->y-yc)*(p1->y-yc);
}
bool f1() {
    ll ans1 = distance(&a), ans2 = distance(&b), ans3 = distance(&c);
    if(ans1 < r*r && ans2 < r*r && ans3 < r*r){
        printf("No\n");         //三个点都在园内一定是No
        return false;
    }else if(ans1 > r*r && ans2 > r*r && ans3 > r*r) return true;   //三个点在园外需要再判断下
    else {
        printf("Yes\n");        //其他情况一定是Yes
        return false;
    }
}
bool segOnCircle(Point *p1, Point *p2) {
    ll a, b, c, dist1, dist2, angle1, angle2;  //ax + by + c = 0
    if(p1->x == p2->x) {
        a = 1, b = 0, c = -p1->x;
    }else if(p1->y == p2->y) {
        a = 0, b = 1, c = -p1->y;
    }else {
        a = p1->y - p2->y;
        b = p2->x - p1->x;
        c = p1->x*p2->y - p1->y*p2->x;
    }
    dist1 = xc*a + yc*b + c;
    dist1 *= dist1;
    dist2 = (a*a + b*b)*r*r;
    if(dist1 > dist2) return 0;
    angle1 = (xc - p1->x) * (p2->x - p1->x) + (yc - p1->y) * (p2->y - p1->y);   //向量OA*AB
    angle2 = (xc - p2->x) * (p1->x - p2->x) + (yc - p2->y) * (p1->y - p2->y);   //向量OB*BA
    if(angle2 > 0 && angle1 > 0) return true;  //必须两个都大于0才是Yes，具体可以在纸上画下就知道为什么了。
    else return false;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>xc>>yc>>r;
        cin>>a.x>>a.y;
        cin>>b.x>>b.y;
        cin>>c.x>>c.y;
        if(f1()) {
            if(segOnCircle(&a, &b) || segOnCircle(&b, &c) || segOnCircle(&c, &a)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
