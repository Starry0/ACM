#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int r = 6371009;
    double PI = acos(-1);
    while(t--) {
        double lat1, lng1, lat2, lng2;
        cin >> lat1 >> lng1 >> lat2 >> lng2;
        lat1+= 180; lat2+=180;
        lat1 *= PI/180;lat2 *= PI/180;
        lng1 *= PI/180;lng2 *= PI/180;
        double x1, x2, y1, y2, z1, z2;
        z1 = r * sin(lat1);
        y1 = r * cos(lat1) * sin(lng1);
        x1 = r * cos(lat1) * cos(lng1);
        z2 = r * sin(lat2);
        y2 = r * cos(lat2) * sin(lng2);
        x2 = r * cos(lat2) * cos(lng2);
        double len1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
        double len2 = 2 * r * asin(len1 / (2 * r));
        printf("%.lf %lf\n",len1,len2);
        // printf("%.lf %.lf %.lf %.lf %.lf %.lf\n",x1,y1,z1,x2,y2,z2 );
        printf("%lld\n",(long long)(len2 - len1 + 0.5));
    }
    return 0;
}
