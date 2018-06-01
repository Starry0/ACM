#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int a[1010];
set<int> st;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), st.insert(a[i]);
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i+1; j <= n; j ++) {
            for(int k = j+1; k <= n; k ++) {
                int x = 0 - a[i] - a[j] - a[k];
                if(x > a[k] && st.count(x)) {
                    return 0*printf("Yes\n");
                }
            }
        }
    }
    printf("No\n");
    return 0;
}
