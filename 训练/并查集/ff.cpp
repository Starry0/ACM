#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 1e5+10;
int fa[maxn], r[maxn];

int find(int x){
    if(fa[x] == x)return x;
    int root = find(fa[x]);
    r[x] = (r[x]+r[fa[x]])%2;
    return fa[x] = root;
}
int uni(int x, int y, int d){
    int a = find(x);
    int b = find(y);
    if(a == b){
        if((r[x]+r[y]+d)%2==0){
            return 1;
        }
        else return 0;
    }else{
        fa[a] = b;
        r[a] = (r[x]+r[y]+d)%2;
        return 1;
    }
}
int main(){
    char s[5];
    int n, m;
    scanf("%d%d",&n,&m);
    for(int j = 0; j < maxn; j ++){
        fa[j] = j;
        r[j] = 0;
    }
    map<int, int> mp;
    int i, a, b, add=0,d;
    for(i = 1; i <= m; i ++){
        scanf("%d %d %s",&a,&b,&s);
        a--;
        if(mp.find(a) == mp.end()) mp[a] = add++;
        int x = mp[a];
        if(mp.find(b) == mp.end()) mp[b] = add++;
        int y = mp[b];
        if(s[0] == 'o') d = 1;
        else d = 0;
        if(uni(x, y, d) == 0) break;
    }
    printf("%d\n",i-1);
    return 0;
}
