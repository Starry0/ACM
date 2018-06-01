#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 1e5+10;
int a[maxn], fa[maxn];
struct Nod{
    int l, r, w;
}edg;
bool operator < (Nod a, Nod b){
    return a.w > b.w;
}
int find(int x){
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        priority_queue<Nod> que;
        int n, sum = 0;
        scanf("%d\n",&n);
        for(int i = 1; i <= n; i ++){
            scanf("%d",&a[i]);
            fa[i] = i;
        }
        for(edg.l = 1; edg.l <= n; edg.l++){
            for(edg.r = 1; edg.r <= n; edg.r++){
                scanf("%d",&edg.w);
                if(edg.l > edg.r){
                    edg.w += a[edg.l]+a[edg.r];
                    que.push(edg);
                }
            }
        }
        while(que.size()){
            edg = que.top();
            que.pop();
            int a = find(edg.l);
            int b = find(edg.r);
            if(a != b){
                fa[a] = b;
            //    cout << edg.w << endl;
                sum += edg.w;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
