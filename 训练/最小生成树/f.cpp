#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 2e6+10;
int a[maxn], fa[maxn];
string s[maxn];
struct Nod{
    int l, r, w;
}edg;
bool operator < (Nod a, Nod b){
    return a.w > b.w;
}
int find(int x){
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
int kruscal(){
    int sum = 0;
    while(que.size()){
        edg = que.top();
        que.pop();
        int a = find(edg.l);
        int b = find(edg.r);
        if(a != b){
            fa[a] = b;
            sum += edg.w;
        }
    }
    return sum;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        priority_queue<Nod> que;
        char ss[10];
        for(int i = 1; i <= n; i ++){
            scanf("%s",ss);
            s[i] = ss;
            fa[i] = i;
        }
        for(edg.l = 1; edg.l <= n; edg.l++){
            for(edg.r = edg.l+1; edg.r <= n; edg.r++){
                edg.w = 0;
                for(int i = 0; i < 7; i ++){
                    if(s[edg.r][i] != s[edg.l][i])
                        edg.w ++;
                }
                que.push(edg);
            }
        }
        int sum = 0;
        while(que.size()){
            edg = que.top();
            que.pop();
            int a = find(edg.l);
            int b = find(edg.r);
            if(a != b){
                fa[a] = b;
                sum += edg.w;
            }
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
    return 0;
}
