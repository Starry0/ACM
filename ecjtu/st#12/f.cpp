#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowvit(x) x&(-x)
#define N 110
#define M 110
using namespace std;
struct Point {
    double x, y;
};
double dist(Point *A, Point *B) {
    return sqrt((A->x - B->x)*(A->x - B->x) + (A->y - B->y)*(A->y - B->y));
}
double area(Point *A, Point *B, Point *C) {
    double a = dist(A, B);
    double b = dist(A, C);
    double c = dist(C, B);
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main() {
    int t;
    Point A, B, C, D, E, F, Q, R, P;
    cin >> t;
    while(t--) {
        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
        double are = area(&A, &B, &C);
        if(are < 0) are = -are;
        printf("%.0f\n",are/7);
    }
    return 0;
}
