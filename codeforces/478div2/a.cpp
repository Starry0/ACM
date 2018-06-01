#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
set<int> st;
string s;
int n;
int main() {
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> s;
        int cnt = 0;
        for(int j = 0; j < s.length(); j ++) {
            cnt |= (1<<(s[j]-'a'));
        }
        st.insert(cnt);
    }
    cout << st.size() << endl;
    return 0;
}
