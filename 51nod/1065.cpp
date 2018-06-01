#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
struct Nod{
    ll id1, id2, num;
}nod[N];
bool cmp(Nod &a, Nod &b) {
    return a.num < b.num;
}
int main() {
    int n;
    cin >> n;
    nod[0].num = nod[0].id1 = nod[0].id2 = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> nod[i].num;
        nod[i].num += nod[i-1].num;
        nod[i].id1 = nod[i].id2 = i;
    }
    sort(nod,nod+1+n,cmp);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(nod[i].num == nod[cnt].num) {
            nod[cnt].id1 = min(nod[i].id1,nod[cnt].id1);
            nod[cnt].id2 = max(nod[i].id2,nod[cnt].id2);
        } else nod[++cnt] = nod[i];
    }
    ll MIN = 1e7;
    for(int i = 0; i < cnt; i ++) {
        if(nod[i].id1<nod[i+1].id2 && nod[i+1].num-nod[i].num > 0 && (nod[i+1].num-nod[i].num) < MIN) {
            MIN = nod[i+1].num - nod[i].num;
        }
    }
    cout << MIN << endl;
    return 0;
}
