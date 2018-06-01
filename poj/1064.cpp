#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int n, k;
const int N = 10010;
double a[N];
bool ok(double x) {
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		ans += int(a[i]/x);
	}
	return ans >= k;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i ++) scanf("%lf",&a[i]);  
	//cin >> n >> k;
	//for(int i = 0; i < n; i ++) cin >> a[i];
	double l = 0.0, r = 2000000.0;
	for(int i = 0; i < 100; i ++) {
		double m = (l+r)/2;
		if(ok(m)) l = m;
		else r = m;
	}
	printf("%.2f\n",floor(l*100)/100);  
	return 0;
}

/*
#include <iostream>
#include <cstdio>  
#include <cmath>  
using namespace std;  
const int N=10005;   
double a[N];  
int n,k;  
bool ok(double x) {  
    int ans = 0;  
    for(int i = 0; i < n; i ++)  
      ans += (int)(a[i]/x);  
    return ans >= k;  
}  

int main() {  
	//scanf("%d%d",&n,&k);
	//for(int i = 0; i < n; i ++) scanf("%lf",&a[i]);  
    cin >> n >> k;
	for(int i = 0; i < n; i ++) cin >> a[i];
	double l = 0, r = 200005.0;  
    for(int i = 0; i < 100; i ++) { 
        double m = (l+r)/2;  
        if(ok(m)) l = m;  
        else r = m;  
    }  
    printf("%.2f\n",floor(r*100)/100);  
    return 0;  
}  
*/