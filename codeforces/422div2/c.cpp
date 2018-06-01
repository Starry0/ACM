// #include <iostream>
// #include <string.h>
// #include <stdio.h>
// #include <algorithm>
// using namespace std;
// const int N = 2e5+10;
// int n, x;
// struct Nod {
//     int l, r, cost, day;
// }nod[N];
// bool cmp(const Nod &a, const Nod &b) {
//     if(a.day != b.day) return a.day < b.day;
//     else return a.cost < b.cost;
// }
// int bin(int x) {
//     int l = 0, r = n-1;
//     if(nod[0].day > x || nod[n-1].day < x) return -1;
//     while(l <= r) {
//         int m = (l+r) >> 1;
//         if(nod[m].day >= x)  r = m-1;
//         else l = m+1;
//     }
//     return l;
// }
// int main() {
//     scanf("%d %d", &n, &x);
//     for(int i = 0; i < n; i++) {
//         scanf("%d %d %d",&nod[i].l, &nod[i].r, &nod[i].cost);
//         nod[i].day = nod[i].r - nod[i].l + 1;
//     }
//     sort(nod, nod+n, cmp);
//     int Min = 2e9+10;
//     bool flag = false;
//     for(int i = 0; i < n; i ++) {
//         if(nod[i].day > x/2) break;
//         int y = x - nod[i].day;
//         int index = bin(y);
//         if(index == -1) continue;
//         if((nod[i].r < nod[index].l || nod[i].l > nod[index].r)){
//             if(i == index) {
//                 if(nod[i].day == nod[i+1].day) index = i+1;
//                 else continue;
//             }
//             if(nod[i].cost + nod[index].cost < Min) {
//                 Min = nod[i].cost + nod[index].cost;
//                 flag = true;
//             }
//         }
//     }
//     printf("%d\n",flag?Min:-1);
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 2e5+10;
vector<pair<int,int> > a[N], b[N];
typedef pair<int,int> P;
const int INF = 2e9+10;
int c[N];
int main() {
    int n, k, l, r, cc;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> l >> r >> cc;
        a[l].push_back(make_pair(r-l+1, cc));
        b[r].push_back(make_pair(r-l+1, cc));
    }
    for(int i = 0; i < N; i ++) c[i] = INF;
    int ans = INF;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < a[i].size(); j ++) {
            P p = a[i][j];
            if(p.first>=k) continue;
			else if(c[k-p.first]<INF) ans=min(ans,p.second+c[k-p.first]);
        }
        for(int j = 0; j < b[i].size(); j ++) {
            P p = b[i][j];
            c[p.first]=min(c[p.first],p.second);
        }
    }
    printf("%d\n",ans==INF?-1:ans);
    return 0;
}
