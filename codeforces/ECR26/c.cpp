#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define N 110
#define M 110
using namespace std;
struct Nod {
    int x, y, z;
}nod[N];

int main() {
    int k, n, m, x, y;
    cin >> k >> n >> m;
    if(n > m ) swap(n, m);
    for(int i = 1; i <= k; i ++) {
        cin >> x >> y;
        nod[i].x = min(x, y);
        nod[i].y = max(x, y);
        nod[i].z = x*y;
    }
    int MAX = 0;
    for(int i = 1; i <= k; i ++) {
        for(int j = i+1; j <= k; j ++) {
            if(max(nod[i].x,nod[j].x) <= n && (nod[i].y+nod[j].y) <= m)
                MAX = max(MAX,nod[i].z+nod[j].z);
            else if((nod[i].x+nod[j].x) <= n && max(nod[i].y,nod[j].y) <= m)
                MAX = max(MAX,nod[i].z+nod[j].z);
            else if(max(nod[i].y,nod[j].x) <= n && (nod[i].x+nod[j].y) <= m)
                MAX = max(MAX,nod[i].z+nod[j].z);
            else if((nod[i].y+nod[j].x) <= n && max(nod[i].x,nod[j].y) <= m)
                MAX = max(MAX, nod[i].z+nod[j].z);
        }
    }
    printf("%d\n",MAX);
    return 0;
}
