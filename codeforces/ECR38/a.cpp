#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
map<char,int> mp;
int main() {
    mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = mp['y']= 1;
    int n;
    cin >>n;
    string s, ss;
    cin >> s;
    for(int i = 0; i < n; i ++) {
        int j = i;
        while(mp[s[i]] && mp[s[i+1]] & i+1 < n) i++;
        ss += s[j];
    }
    cout << ss << endl;
    return 0;
}
