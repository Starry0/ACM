#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e+5;
int fa[maxn];
bool vis[maxn];
int find(int x){
    int r = x;
    while(fa[r] != r)
        r = fa[r];
    return r;
}
int uni(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a == b) return false;
    fa[a] = b;
    return true;
}

int main(){
    int a, b;
    while(~scanf("%d%d",&a,&b)&&(a!=-1 && b!=-1)){
        int flag = 1, ans = 0;
        if(a == 0 && b == 0){
            printf("Yes\n");
            continue;
        }
        for(int i = 0; i < maxn; i ++){
            fa[i] = i;
            vis[i] = 0;
        }
        int minx = 9999999;
        int Maxn = -1;
        while(a||b){
            minx = min(minx,min(a,b));
            Maxn = max(Maxn,max(a,b));
            vis[a] = 1;vis[b] = 1;
            if(!uni(a,b)) flag = 0;
            scanf("%d%d",&a,&b);
        }
        if(flag == 0){
            printf("No\n");
        }else{
            for(int i = minx; i <= Maxn; i++){
                if(vis[i]&&i == fa[i]) ans++;
            }
            if(ans == 1)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
