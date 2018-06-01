#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int main(){
    int n, k, t;
    cin >> n >> k >> t;
    if(t <= k) {
    	printf("%d\n",t);
    } else if(t <= n) {
    	printf("%d\n",k);
    } else {
    	printf("%d\n",k+n-t);
    }
    return 0;
}
