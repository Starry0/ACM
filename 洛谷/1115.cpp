#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int N = 200010;
int n, a[N];
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) scanf("%d",a+i);
	ll Max = 0, maxn = 0;
	for(int i = 0; i < n; i ++){
		maxn = max(0LL,maxn) + a[i];
		Max = max(Max,maxn);
	}
    if(Max > 0) return 0*printf("%lld\n",Max);
    Max = -1e9;
    for(int i = 0; i < n; i ++) {
        Max = max(Max, 1LL*a[i]);
    }
    cout << Max << endl;
	return 0;
}
