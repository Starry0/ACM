#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const double PI = acos(-1.0);
struct complex {
    double r,i;
    complex(double _r = 0,double _i = 0) {
        r = _r; i = _i;
    }
    complex operator +(const complex &b) {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b) {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b) {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(complex y[],int len) {
    int i,j,k;
    for(i = 1, j = len/2;i < len-1;i++) {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k)j += k;
    }
}
void fft(complex y[],int len,int on) {
    change(y,len);
    for(int h = 2;h <= len;h <<= 1) {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h) {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++) {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

const int MAXN = 400040;
complex x1[MAXN];
int a[MAXN/4], n, m;
ll num[MAXN], sum[MAXN];

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		memset(num, 0, sizeof(num));
		for(int i = 0; i < n; i ++) {
			cin >> a[i];
			num[a[i]]++;
		}
		sort(a,a+n);
		int len = 1, len1 = a[n-1]+1;
	    while(len < 2*len1)len <<= 1;
	    for(int i = 0;i < len1; i ++)
	        x1[i] = complex(num[i],0);
	    for(int i = len1;i < len; i ++)
	        x1[i] = complex(0,0);
	    fft(x1,len,1);
	    for(int i = 0;i < len;i++)
	        x1[i] = x1[i]*x1[i];
	    fft(x1,len,-1);
	    for(int i = 0;i < len;i++)
	        num[i] = (long long)(x1[i].r+0.5);

	   	len = a[n-1]*2;
	   	for(int i = 0; i < n; i ++) num[a[i]+a[i]]--;
	   	for(int i = 0; i <= len; i ++) {
	   		num[i] /= 2;
	   	}
	   	sum[0] = 0;
	   	for(int i = 1; i <= len; i ++) sum[i] = sum[i-1] + num[i];
	   	ll ans = 0;
	   	for(int i = 0; i < n; i ++) {
	   		ans += sum[len]-sum[a[i]];
	   		ans -= 1LL*i*(n-i-1);
	   		ans -= 1LL*(n-i-1)*(n-i-2)/2;
	   		ans -= 1LL*(n-1);
	   	}
	   	// for(int i = 0; i < len; i ++) printf("%d %lld\n",i,sum[i] );
	   	ll tot = 1LL*n*(n-1)*(n-2)/6;
	   	// printf("%lld %lld\n",ans,tot);
	   	printf("%.7lf\n",1.0*ans/tot);
	}
	return 0;
}