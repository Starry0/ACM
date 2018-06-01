#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e4+10;
struct Ani{
    int fa, relation;
}ani[maxn];
int find(int x){
    if(ani[x].fa == x)return ani[x].fa;
    int tmp = ani[x].fa;
    ani[x].fa = find(ani[x].fa);
    ani[x].relation = (ani[tmp].relation + ani[x].relation) % 3;
    return ani[x].fa;
}
void uni(int x, int y, int a, int b, int d){
    ani[b].fa = a;
    ani[b].relation = (ani[x].relation + (d-1) + (3-ani[y].relation))%3;
}
int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i = 0; i <= n; i ++){
        ani[i].fa = i;
        ani[i].relation = 0;
    }
    int x, y, d, ans = 0;
    for(int i = 0; i < k; i ++){
        scanf("%d%d%d",&d,&x,&y);
        if(x > n || y > n){
            ans++;
        }
        else{
            if(d == 2 && x == y){
                ans++;
            }
            else{
                int a = find(x);
                int b = find(y);
                if(a != b){
                    uni(x, y, a, b, d);
                }else{
                    if(d == 1)if(ani[x].relation != ani[y].relation) ans++;
                    if(d == 2)if((ani[y].relation + 3 - ani[x].relation)%3 != 1) ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
