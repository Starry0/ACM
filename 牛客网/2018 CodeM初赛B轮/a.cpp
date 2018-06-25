#include <bits/stdc++.h>
using namespace std;
const int N = 550;
const int M = 1e5+10;
int n, m, k, a[N][N];
struct Nod{
    int x, y, z;
    string s;
}nod[M];
bool cmp(const Nod &a, const Nod &b) {return a.s < b.s;}
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < k; i ++) {
        cin >> nod[i].x >> nod[i].y >> nod[i].z >> nod[i].s;
    }
    sort(nod,nod+k,cmp);
    int pos, MAX = 0, ans = 0;
    for(int i = 0; i < k; i ++) {
        if(nod[i].z) {
            if(!(--a[nod[i].x][nod[i].y])) ans--;
        } else {
            if(!(a[nod[i].x][nod[i].y]++)) ans++;
            if(ans >= MAX) {
                MAX = ans;
                pos = i;
            }
        }
    }
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= pos; i ++)
        if(nod[i].z) a[nod[i].x][nod[i].y]--;
        else a[nod[i].x][nod[i].y]++;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++)
            printf("%d",a[i][j]?1:0);
        printf("\n");
    }
    return 0;
}
