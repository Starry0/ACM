#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[110];
map<int,int> mp;
vector<int> vs;
int main() {
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = n-1; i >= 0; i --) {
        if(!mp[a[i]]) {
            vs.push_back(a[i]);
            mp[a[i]] = 1;
        }
    }
    cout << vs.size() << endl;
    int len = vs.size();
    for(int i = len-1; i >= 0; i --) printf("%d ",vs[i]);
    printf("\n");
    return 0;
}
