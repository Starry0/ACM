#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 30010;
int fa[N], son[N];
int main() {
    int t;
    for(int i = 0; i < N; i ++) fa[i] = son[i] = i;
    scanf("%d", &t);
    char ch;
    int x, y, ans1, ans2;
    while(t--) {
        cin >> ch >> x >> y;
        if(ch == 'M') {
            while(fa[x] != x) x = fa[x];
            while(son[y] != y) y = son[y];
            fa[x] = y;
            son[y] = x;
        } else {
            ans1 = ans2 = 0;
            while(fa[x] != x) {
                x = fa[x];
                ans1++;
            }
            while(fa[y] != y) {
                y = fa[y];
                ans1++;
            }
            if(x == y) printf("%d\n",abs(ans1-ans2)-1);
            else printf("-1\n");
        }
    }
    return 0;
}
