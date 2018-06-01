#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
// int a[N];
map<int, int> mp;
int main() {
    int n, x;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) {
        scanf("%d",&x);
        mp[x]++;
        mp[x+1]++;
        mp[x-1]++;
    }
    map<int, int> ::iterator it;
    int MAX = 1;
    for(it = mp.begin(); it != mp.end(); ++it) {
        if(MAX < (*it).second){
            MAX = (*it).second;
        }
    }
    printf("%d\n",MAX);
    return 0;
}
