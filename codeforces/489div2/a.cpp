#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<int> st;
int main() {
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        if(x != 0) st.insert(x);
    }
    cout << st.size() << endl;
    return 0;
}
