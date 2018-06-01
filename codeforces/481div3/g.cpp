#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
struct Nod{
    int a, b, c, id;
}nod[N];
bool cmp(Nod &a, Nod &b) {
    return a.b < b.b;
}
int b[N];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        cin >> nod[i].a >> nod[i].b >> nod[i].c;
        if(b[nod[i].b] != 0) return 0*printf("-1\n");
        b[nod[i].b] = m+1;
        nod[i].id = i+1;
    }
    for(int i = 0; i < m; i ++) {
        int ans = 0;
        for(int j = nod[i].a; j < nod[i].b; j++) {
            if(b[j] == 0) {
                b[j] = nod[i].id;
                ans++;
            }
            if(ans == nod[i].c) break;
        }
        if(ans < nod[i].c) return 0*printf("-1\n");
    }
    for(int i = 1; i <= n; i ++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}
