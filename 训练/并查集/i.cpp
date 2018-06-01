#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e3+10;
int n, d;
int fa[maxn];
bool vis[maxn];
struct Nod{
    int pre;
    int x, y;
}nod[maxn];
int find(int x){
    return x == nod[x].pre? x : find(nod[x].pre);
}
void uni(Nod p1, Nod p2){
    int a = find(p1.pre);
    int b = find(p2.pre);
    if(a != b){
        if((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) <= d*d){
            nod[a].pre = b;
        }
    }
}
int main(){
    scanf("%d%d",&n,&d);
    for(int i = 0; i < maxn; i++){
        nod[i].pre = i;
    }
    int a, b;
    for(int i = 1; i <= n; i ++){
        scanf("%d%d",&nod[i].x,&nod[i].y);
    }
    char s;
    while(cin>>s){
        if(s == 'O'){
            scanf("%d",&a);
            vis[a] = 1;
            for(int i = 1; i <= n; i ++){
                if(vis[i] && i!=a){
                    uni(nod[i],nod[a]);
                }
            }
            //cout << fa[2] << endl;
        }else{
            scanf("%d%d",&a,&b);
            //cout << fa[5] << ' ' << fa[6] << endl;
            if(find(a) == find(b)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
