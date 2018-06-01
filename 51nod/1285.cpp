#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int a[N], n, b[N];
vector<int> vs;
bool ok(int x) {
    if(b[n] < x) return false;
    int len = n/x;
    for(int i = 0; i < x; i ++) {
        if(b[(i+1)*len]-b[i*len+1] == 0) return false;
    }
    return true;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 2; i < n; i ++) {
        b[i+1] = (a[i]>a[i-1]&&a[i]>a[i+1]) + b[i];
    }
    if(!b[n])return 0*printf("0\n");
    // for(int i = 1; i<= n; i ++) printf("%d ",b[i] );printf("\n" );
    for(int i = 2; i <= sqrt(n); i ++) {
        if(n%i==0) {
            vs.push_back(i);
            vs.push_back(n/i);
        }
    }
    sort(vs.begin(),vs.end());
    for(int i = vs.size()-1; i >= 0; i --) {
        if(ok(vs[i])) return 0*printf("%d\n",vs[i]);
    }
    printf("1\n");
    return 0;
}
