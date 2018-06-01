#include <bits/stdc++.h>
using namespace std;
string s[35] = {"algorithm", "bitset", "cctype", "cerrno", "clocale", "cmath",
 "complex", "cstdio", "cstdlib", "cstring", "ctime", "deque", "exception", "fstream", "functional",
 "limits", "list", "map", "iomanip", "ios", "iosfwd", "iostream", "istream", "ostream", "queue", "set", "sstream",
 "stack", "stdexcept", "streambuf", "string", "utility", "vector", "cwchar", "cwctype"};
int main() {
    int t;
    map<string,int> mp;
    for(int i = 0; i < 35; i ++) {
        mp[s[i]]++;
    }
    cin >>t;
    while(t--) {
        string ss;
        cin >> ss;
        if(mp[ss]) cout << "Qian\n";
        else cout << "Kun\n";
    }
    return 0;
}
