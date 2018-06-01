#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 2e6+10;
int x[MAX],yy[MAX],xx[MAX];
struct Nod{
    int x, y;
}nod[MAX],pos[MAX];
bool cmp(Nod a, Nod b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
ll C(int a, int b){
    if(b < 2) return 0;
    ll ans = 1;
    if(a < b-a) a = b - a;
    for(int i = a+1; i <= b; i ++) ans*=i;
    for(int i = 1; i <= b-a; i ++) ans/=i;
    return ans;
}
bool fun(int x1, int y1, int x2, int y2){
    int xx = abs(x1-x2), yy = abs(y1-y2);
    if((xx+yy)*(xx+yy) == (xx*xx+yy*yy)) return true;
    else return  false;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        scanf("%d%d",&nod[i].x,&nod[i].y);
        xx[nod[i].x]++;yy[nod[i].y]++;
    }
    sort(nod,nod+n,cmp);
    int k = 0;
    for(int i = 0; i < n; i ++){
        if(xx[nod[i].x] < 2 && yy[nod[i].y] < 2) continue;
        pos[k].x = nod[i].x;pos[k++].y = nod[i].y;
    }
    ll ans = 0;
    for(int i = 0; i < k; i ++){
        for(int j = i+1; j < k; j ++){
            if(fun(pos[i].x,pos[i].y,pos[j].x,pos[j].y)){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
