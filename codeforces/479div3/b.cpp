#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string,int> mp;
int main() {
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n-1; i ++) {
        string ss = s.substr(i,2);
        mp[ss]++;
    }
    n = 0;
    map<string,int> ::iterator it = mp.begin();
    for(; it!=mp.end(); it++) {
        if((*it).second > n) {
            n = (*it).second;
            s = (*it).first;
        }
    }
    cout << s<< endl;
    return 0;
}
