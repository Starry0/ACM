#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], b[N];
int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1},
    dy[] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
int main() {
    int n, s = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    if(n <= 2) return 0*printf("0\n");
    int ans = 1e7;
    for(int i = 0; i < 9; i ++) {
        int cnt = 0, flag = 1;
        if(dx[i]) cnt++;
        if(dy[i]) cnt++;
        b[0] = a[0] + dx[i];
        b[1] = a[1] + dy[i];
        int tmp = b[1] - b[0];
        for(int j = 2; j < n; j ++) {
            if(a[j]+1-b[j-1] == tmp) {
                b[j] = a[j] + 1;
                cnt++;
            } else if(a[j] - b[j-1] == tmp) b[j] = a[j];
            else if(a[j]-1-b[j-1] == tmp) {
                b[j] = a[j]-1;
                cnt++;
            } else {
                flag = 0;
                break;
            }
        }
        if(flag) ans = min(ans, cnt);
    }
    printf("%d\n",ans==1e7?-1:ans);
    return 0;
}
