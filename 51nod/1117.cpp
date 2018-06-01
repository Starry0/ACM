#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > que;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x;
        que.push(x);
    }
    int ans = 0;
    while(que.size() != 1) {
        int a = que.top();
        que.pop();
        int b = que.top();
        que.pop();
        ans += a+b;
        que.push(a+b);
    }
    cout << ans << endl;
    return 0;
}
