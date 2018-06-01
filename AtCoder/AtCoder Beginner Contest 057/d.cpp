#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;

ll vi[55];
bool cmp(ll x, ll y){
    return x > y;
}
ll CC(int a, int b){
    if(a<b-a) a = b-a;
    ll ans = 1;
    for(int i = a + 1; i <= b; i++)
        ans *=i;
    for(int i = b - a; i > 0; i --)
        ans /= i;
    return ans;
}
int main(){
    int n, a, b;
    //cout << CC(1,3)<<endl;
    while(~scanf("%d%d%d",&n,&a,&b)){
        for(int i = 0; i < n; i ++){
            scanf("%lld",&vi[i]);
        }
        sort(vi, vi+n,cmp);
        double avg = 0.0;
        for(int i = 0; i < a; i++){
            avg += vi[i];
        }
        printf("%.6lf\n",avg/a*1.0);
        int pos1 = a - 1;
        while(vi[pos1] == vi[pos1+1])pos1++;
        int pos2 = a - 1;
        if(pos2 != 0)
        while(vi[pos2] == vi[pos2-1])pos2--;
        //cout << pos1 << ' ' << pos2 << endl;
        if(vi[pos1] == vi[0]){
            pos1++;
            if(pos1 >= b) pos1 = b;
            ll k = 0;
            //cout << a << ' ' << pos1 << endl;
            for(int i = a; i <= pos1; i++){
                k += CC(i,pos1);
            }
            cout << k << endl;
        }
        else{
            int c = a - pos2 + 1;
            int d = pos1 - pos2 + 1;
            cout << CC(c,d) << endl;
        }
    }
    return 0;
}
