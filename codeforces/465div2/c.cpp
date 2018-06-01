#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
    double r, x1, x2, y1, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    if(dis(x1,y1,x2,y2) >= r) {
        printf("%lf %lf %lf\n",x1,y1,r);
    } else if(x1 == x2 && y1 == y2){
        printf("%lf %lf %lf\n",x1,y1+r/2,r/2);
    }else{
        double d = dis(x1,y1,x2,y2);
        double R = (r+d)/2;
        printf("%lf %lf %lf\n",x2+(x1-x2)*R/d,y2+(y1-y2)*R/d,R);
    }
    return 0;
}
