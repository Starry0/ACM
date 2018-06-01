#include <bits/stdc++.h>
using namespace std;
const int N = 110;
bool vis[N];
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0, id = 0;
    for(int i = 1; i <= n; i ++) {
        int j = 0;
        while(true) {
            id ++;
            if(id > n) id -= n;
            if(!vis[id]) {
                j++;
            }
            // printf("%d %d\n",id,j==3);
            if(j == m) break;
        }
        printf("%d ",id);
        vis[id] = 1;
    }
	return 0;
}
