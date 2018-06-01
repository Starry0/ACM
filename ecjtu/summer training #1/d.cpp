#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int R = 12*60*60;
const int D = 24*60*60;

int main(){
    int k,m;
    while(scanf("%d%d",&k,&m)!=EOF){
        int cnt = abs(k-m);
        if(cnt == 0){
            printf("%d %d 12:00\n",k,m);
            continue;
        }
        double d = R*1.0/cnt;
        int t = (int)(d*(D-k)/60+0.5)%D;
        int h = t/60;
        h%=12;
        if(h==0) h = 12;
        int mm = t%60;
        printf("%d %d %02d:%02d\n",k,m,h,mm);
    }
    return 0;
}
