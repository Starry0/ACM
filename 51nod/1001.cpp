//set或二分
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 50010;
int a[MAX], k, n;
set<int> st, st1;

int main() {
    cin>>k>>n;
    for(int i = 1; i <= n; i ++) scanf("%d",&a[i]),st.insert(a[i]);
    sort(a+1, a+1+n);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x = k - a[i];
        if(st.count(x) && x != a[i] && !st1.count(x))
        printf("%d %d\n",a[i], x), st1.insert(a[i]),st1.insert(x), ans++;
    }
    if(ans == 0)
        printf("No Solution\n");
    return 0;
}
