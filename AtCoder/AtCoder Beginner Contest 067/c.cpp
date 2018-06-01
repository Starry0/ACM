/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
const int MAX = 2e5+100;
ll a[MAX];
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i ++)cin>>a[i];
	ll x = a[0], y = a[n-1];
	int l = 1, r = n-2;
	while(l <= r){
		ll xx = a[l]+x;
		ll yy = a[r]+y;
		if(abs(xx-y)>=abs(x-yy)){
			y = yy;
			r--;
		}else{
			x = xx;
			l++;
		}
	}
	cout << abs(x-y) << endl;
	return 0;
}*/



/*#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int MAX = 2e5+10;
ll a[MAX];

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i ++)cin>>a[i];
	ll x = a[0];
	ll y = a[n-1];
	for(int i = 1, j = n-2; i <= j; ){
		if(abs(x+a[i]-y) >= abs(y+a[j]-x)){
			y += a[j--];
		}else {
			x += a[i++];
		}
	}
	cout << abs(x-y) << endl;
	return 0;
}*/



#include <iostream>
#include <cmath>
#define lowbit(x)  x&(-x)
#define ll long long
using namespace std;
const int MAX = 2e5+10;
ll a[MAX], sum[MAX];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i ++){
		cin>>a[i];
		sum[i] = sum[i-1]+a[i];
	}
	ll Min = 1LL*50000000000000000;
	for(int i = 1; i < n; i ++){
		ll cnt = sum[n]-2LL*sum[i];
		if(Min > abs(cnt))Min = abs(cnt);
	}
	cout << Min << endl;
}