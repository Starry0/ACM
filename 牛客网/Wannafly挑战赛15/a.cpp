#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
struct Nod{
    int x, y;
}nod[N];
bool cmp(Nod &a, Nod &b) {
    return a.x > b.x;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> nod[i].x >> nod[i].y;
    sort(a,a+n);
    sort(nod,nod+m,cmp);
    int ans = 0, id = n-1;
    priority_queue<int,vector<int>, greater<int> >que;
    for(int i = 0; i < m; i ++) {
        if(nod[i].x >= a[id]) {
            que.push(nod[i].y);
        } else {
            if(que.empty()) return 0*printf("-1\n");
            ans += que.top();
            que.pop();
            id--;
            if(id == -1) break;
        }
    }
    while(!que.empty()&&id!=-1) {
        ans += que.top();
        que.pop();
        id--;
    }
    // printf("%d\n",id);
    if(id == -1) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
