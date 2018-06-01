#include <iostream>
#include <cstdio>
using namespace std;
struct Nod{
    int to;
    int w;
    int next
}g[100];
int head[100];

int main(){
    int n, m, x, y, z;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        cin >> x >> y >> z;
        g[i].to = y;
        g[i].w = z;
        g[i].next = head[x];
        head[x] = i;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = head[i]; j != -1; )
    }
}
