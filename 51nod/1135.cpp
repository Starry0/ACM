#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define ll long long
using namespace std;
const int MAX = 50000;
int prime[MAX],ppri[MAX];
void get_prime(){
	for(int i = 2; i <= MAX; i ++){
		if(!prime[i])prime[++prime[0]] = i;
		for(int j = 1; j <= prime[0]&& prime[j] < MAX/i; j ++){
			prime[prime[j]*i] = 1;
			if(i%prime[j] == 0)break;
		}
	}
}
int get_num(int n){
	int cnt = 0;
	for(int i = 1; prime[i]*prime[i] <= n; i ++){
		if(n%prime[i] == 0){
			ppri[++cnt] = prime[i];
			while(n%prime[i] == 0)n/=prime[i];
		}
	}
	if(n>1)ppri[++cnt]=n;
	return cnt;
}
ll mod_mul(ll a, ll b, ll n){
    ll cnt = 0LL;
    while(b){
        if(b&1LL) cnt = (cnt+a)%n;
        a=(a+a)%n;
        b >>= 1LL;
    }
    return cnt;
}
ll mod_exp(ll a, ll b, ll n){
    ll res = 1LL;
    while(b){
        if(b&1LL) res = mod_mul(res,a,n);
        a = mod_mul(a,a,n);
        b >>= 1LL;
    }
    return res;
}
int main(){
	int n;
	cin>>n;
	get_prime();
	int cnt = get_num(n-1);
	for(int a = 1; ; a ++){
		int flag1 = 1;
		for(int i = 1; i <= cnt; i ++){
			int t = (n-1)/ppri[i];
			if(mod_exp(a,t,n)==1){
				//存在a^((n-1)/ppri[i]) mod n = 1， 则 a 不是质数p的原根
				flag1 = 0;break;
			}
		}
		if(flag1)return 0*printf("%d\n",a);
	}
	return 0;
}
