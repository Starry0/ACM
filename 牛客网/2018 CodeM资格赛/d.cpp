#include <bits/stdc++.h>
using namespace std;
const int N = 550;
const int M = 10;
int n, m, k, c, w[M], sum, id, MAX[M];
struct Nod{
    int a[M], id;
    double tot;
    Nod(){
        tot = 0;
    }
}nod[N];
set<int> st[N];
bool cmp(const Nod &a,const Nod &b) {
    return a.tot > b.tot;
}
int main() {
    cin >> n >> m >> k >> c;
    for(int i = 0; i < m; i ++) cin >> w[i], sum += w[i];
    for(int i = 0; i < n; i ++) {
        nod[i].id = i+1;
        for(int j = 0; j < m; j ++) {
            cin >> nod[i].a[j];
            if(nod[i].a[j] == -1) {
                id = j;
            }
        }
    }
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            MAX[i] = max(MAX[i],nod[j].a[i]);
         }
    }
    for(int i = 0; i <= c; i ++) {
        MAX[id] = max(MAX[id],c);
        for(int j = 0; j < n; j ++) {
            nod[j].tot = 0;
            for(int l = 0; l < m; l ++) {
                if(nod[j].a[l] != -1) nod[j].tot += 1.0*nod[j].a[l]/MAX[l]*w[l]/sum;
                else nod[j].tot += 1.0*i/MAX[l]*w[l]/sum;
                // if(i == 200) printf("%lf %d-=\n", nod[j].tot,MAX[l]);
            }
        }
        sort(nod,nod+n,cmp);
        bool flag = 0;
        // printf("%d\n",i);
        if(fabs(nod[k-1].tot - nod[k].tot) <= 1e-6) flag = 1;
        for(int j = 0; j < n; j ++) {
            if(nod[j].tot > nod[k-1].tot) {
                st[nod[j].id].insert(1);
            } else if(fabs(nod[j].tot - nod[k-1].tot) <= 1e-6 && !flag) {
                st[nod[j].id].insert(1);
            } else if(fabs(nod[j].tot - nod[k-1].tot) <= 1e-6 && flag) {
                st[nod[j].id].insert(3);
            } else if(nod[j].tot < nod[k-1].tot) {
                st[nod[j].id].insert(2);
            }
            // printf("%d %lf\n",nod[j].id,nod[j].tot);
        }
        // printf("\n");
    }
    for(int i = 1; i <= n; i ++) {
        // printf("%d %d\n",i,st[i].size() );
        if(st[i].size() >= 2) printf("3\n");
        else if(st[i].size() == 1) {
            if(st[i].count(1)) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
