#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
char str[30];
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
bool ispirme(ll n){
	int respat = 5;
    if(n==2LL || n==3LL || n==5LL || n==7LL || n==11LL) return true;
    if(n==1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11)) return false;
    
    int k = 0;
    ll d = n-1; 
    
    while(!(d&1LL)){
        k++; d >>= 1LL;
    }
    srand((ll)time(0));
    for(int i = 0; i < respat; i ++) {
        ll a = rand()%(n-2)+2;    
        ll x = mod_exp(a,d,n);
        ll y = 0LL;
        for(int j = 0; j < k; j ++){
            y = mod_mul(x,x,n);
            if(1LL==y && 1LL!=x && n-1LL!=x)return false; 
            x = y;
        }
        if(1LL != y) return false;  
    }
    return true;
}
int main() {
	ll x = 0, y = 0;
	cin >> str;
	int len = strlen(str);
	for(int i = 0; i < len; i ++) {
		if(str[i] == '3' || str[i] == '4' || str[i] == '7') return 0*printf("no\n");
		x = x*10 + str[i]-'0';
	}
	for(int i = len-1; i >= 0; i --) {
		ll tmp = str[i] - '0';
		if(tmp == 9) tmp = 6;
		else if(tmp == 6) tmp = 9;
		y = y*10 + tmp;
	}
	// cout << x << ' ' << y << endl;
	if(ispirme(x) && ispirme(y)) printf("yes\n");
	else printf("no\n");
	return 0;
}