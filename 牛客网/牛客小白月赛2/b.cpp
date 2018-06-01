#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >>t;
    while(t--) {
        double px,py,ux,uy,vx,vy;
        cin >> px >> py >> ux >> uy >> vx >> vy;
        if(ux == vx) printf("%.6lf %.6lf\n",ux,py);
        else if(uy == vy) printf("%.6lf %.6lf\n",px,uy);
        else{
            double a = (uy-vy)/(ux-vx);
            double x = (px+a*py+a*a*ux-a*uy)/(a*a+1);
            double y = py + (px - x) / a;
            printf("%.6lf %.6lf\n",x,y);
        }
    }
    return 0;
}
