#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Nod{
    vector<int> l, r;
}nod[66];

int main() {
    int n, m;
    while(scanf("%d%d",&n,&m) != EOF) {
        for(int i = 0; i <= 60; i ++) {
            nod[i].l.clear();
            nod[i].r.clear();
        }
        int op, l, r , c;
        while(m--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d%d",&l,&r,&c);
                nod[c].l.push_back(l);
                nod[c].r.push_back(r);
            } else {
                scanf("%d%d",&l,&r);
                int ans = 0;
                for(int i = 0; i <= 60; i ++) {
                    for(int j = 0; j < nod[i].l.size(); j ++) {
                        if(nod[i].l[j] <= r && nod[i].r[j] >= l) {
                            ans++;
                            break;
                        }
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}
