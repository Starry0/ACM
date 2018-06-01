#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        ll n, m, v, k;
        cin>>n>>m>>v>>k;
        if(m >= n) printf("0\n");
        else if((m-v)*k <= m) printf("-1\n");
        else {
            int ans = 0;
            while(true) {
                m = (m-v)*k;
                ans++;
                if(m >= n) {
                    printf("%d\n",ans);
                    break
                }
            }
        }
    }
    return 0;
}
