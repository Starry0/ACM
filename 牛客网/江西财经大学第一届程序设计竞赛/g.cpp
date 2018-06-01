#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 30;
int h[N], p[N];
struct Nod {
    int s, e, h, p;
}nod[22];
bool cmp(Nod &a, Nod &b) {
    return a.s < b.s;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(h,0,sizeof(h));
        memset(p,0,sizeof(p));
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> nod[i].s >> nod[i].e >> nod[i].h >> nod[i].p;
        }
        sort(nod,nod+n,cmp);
        for(int i = 0; i < n; i ++) {
            for(int j = nod[i].e; j <= 24; j ++) {
                if(h[j] < h[nod[i].s] + nod[i].h) {
                    h[j] = h[nod[i].s] + nod[i].h;
                    p[j] = p[nod[i].s] + nod[i].p;
                } else if(h[j] == h[nod[i].s] + nod[i].h) {
                    p[j] = p[nod[i].s] + nod[i].p;
                }
            }
        }
        cout << h[24] << ' ' << p[24] << endl;
    }
    return 0;
}
