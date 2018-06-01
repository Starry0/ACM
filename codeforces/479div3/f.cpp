#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 2e5+10;
map<int,int> mp;
int a[N];
int main() {
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(mp[a[i]-1]) {
            mp[a[i]] = mp[a[i]-1]+1;
        } else mp[a[i]] = 1;
    }
    map<int,int> ::iterator it = mp.begin();
    int MAX = 0, id;
    for(;it != mp.end(); ++it) {
        if(MAX < (*it).second){
            MAX = (*it).second;
            id = (*it).first;
        }
    }
    cout << MAX << endl;
    int MIN = id - MAX + 1;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == MIN) {
            printf("%d ",i);
            MIN++;
        }
        if(MIN > id) break;
    }
    return 0;
}
