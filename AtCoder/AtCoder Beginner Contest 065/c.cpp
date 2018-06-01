    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int Mod = 1e9+7;
    ll AA(ll x){
    	ll ans = 1, i = 1;
    	while(i <= x){
    		ans = (ans*i)%Mod;
    		i++;
    	}
    	return ans%Mod;
    }
    int main(){
    	ll n,m;
    	//cout << AA(100000) << endl;
    	cin >> n >> m;
    	if(abs(n-m) > 1){
    		cout << 0 << endl;
    		return 0;
    	}
    	if(abs(n-m) == 1){
    		cout << (AA(n)*AA(m))%Mod << endl;
    	}else {
    		cout << ((AA(n)*2%Mod)*AA(m))%Mod << endl;
    	}
    	return 0;
    }