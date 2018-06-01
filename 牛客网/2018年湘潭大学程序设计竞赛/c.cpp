#include <bits/stdc++.h>
using namespace std;
int ans[110][110];
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int MAX = 0;
        while(n--) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            for(int i = a; i < c; i ++) {
                for(int j = b; j < d; j ++) {
                    ans[i][j] ++;
                    MAX = max(MAX,ans[i][j]);
                }
            }
        }
        cout << MAX << endl;
        memset(ans, 0, sizeof(ans));
    }
    return 0;
}
