#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];
int main( ) {
    int n;
    std::cin >> n;
    int ans = (n-1)*n+1, ans1 = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < n; j ++) {
            printf("%d ",ans1++);
        }
        printf("%d\n",ans++);
    }
    return 0;
}
