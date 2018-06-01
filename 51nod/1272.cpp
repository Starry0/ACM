#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+10;
int pre[N], n;
struct Nod{
    int num,id;
}nod[N];
bool cmp(Nod &a, Nod &b) {
    if(a.num != b.num) return a.num < b.num;
    else return a.id < b.id;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> nod[i].num;
        nod[i].id = i;
    }
    sort(nod+1,nod+1+n,cmp);
    pre[n] = nod[n].id;
    for(int i = n-1; i > 0; i --) {
        pre[i] = max(pre[i+1],nod[i].id);
    }
    int MAX = 0;
    for(int i = 1; i < n; i ++) {
        MAX = max(MAX, pre[i+1]-nod[i].id);
    }
    cout << MAX << endl;
    return 0;
}
