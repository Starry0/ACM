#include <iostream>
#include <algorithm>
#include <math.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
char s1[N], s2[N];
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
complex x1[MAXN], x2[MAXN];
int a[MAXN/4], n, m;
ll num[MAXN], ans[MAXN];
void slove(char ch) {
	int len = 1;
    while(len < 2*n || len < 2*m)len <<= 1;
    for(int i = 0;i < n;i++)
        x1[i] = complex(s1[i]==ch,0);
    for(int i = n;i < len;i++)
        x1[i] = complex(0,0);
    for(int i = 0;i < m;i++)
        x2[i] = complex(s2[i]==ch,0);
    for(int i = m;i < len;i++)
        x2[i] = complex(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i = 0;i < len;i++)
        x1[i] = x1[i]*x2[i];
    fft(x1,len,-1);
    for(int i = 0;i < len;i++)
        num[i] = (long long)(x1[i].r+0.5);
   	for(int i = 0; i < len; i ++) 
   		ans[i] += num[i];
}
int main() {
	cin >> n >> m;
	cin >> s1 >> s2;
	for(int i = 0; i < n; i ++) {
		if(s1[i] == 'R') s1[i] = 'P';
		else if(s1[i] == 'P') s1[i] = 'S';
		else if(s1[i] == 'S') s1[i] = 'R';
	}
	for(int i = 0; i < m/2; i ++) swap(s2[i], s2[m-i-1]);
	slove('R');
	slove('S');
	slove('P');
	ll MAX = 0;
	for(int i = m-1; i < n+m-1; i ++) MAX = max(MAX, ans[i]);
	cout << MAX << endl;
	return 0;
}