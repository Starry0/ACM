#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
const int MAX = 50010;
const int Inf = 1<<27;
int k,n;
struct Nod{
	int w,p;
	double a;
}nod[MAX];
bool cmp(Nod A, Nod B){
	return A.a > B.a;
}
ll gcd(ll a, ll b){
	return b==0?a:gcd(b,a%b);
}
int aa,bb,aaa,bbb;
bool C(double x){
	for(int i = 0; i < n; i ++){
		nod[i].a = nod[i].p-x*nod[i].w;
	}
	sort(nod,nod+n,cmp);
	double sum = 0;
	aa = bb =0;
	for(int i = 0; i < k; i ++){
		aa += nod[i].p;
		bb += nod[i].w;
		sum += nod[i].a;
	}
	return sum >= 0;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; i ++)
		scanf("%d %d",&nod[i].w,&nod[i].p);
	double l = 0, r = 1.0*Inf;
	for(int i = 0; i < 100; i ++){
		double m = (l+r)/2;
		if(C(m)){
			l=m;
			aaa = aa;
			bbb = bb;
		}
		else r = m;
	}
	printf("%lld/%lld\n",aaa/gcd(aaa,bbb),bbb/gcd(aaa,bbb));
	return 0;
}