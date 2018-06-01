#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#define ll long long
const int Mod = 100000007;
using namespace std;
typedef pair<int,int> P;
int n, m, k, x, y;
ll pow(ll x, int y) {
	if(y == 1) return x%Mod;
	if(y&1) return (x%Mod)*pow(x*x%Mod,y/2)%Mod;
	else return pow(x*x%Mod,y/2)%Mod;
	/*
	ll ret=1;
    while(y){
        if(y&1)
            ret=ret*x%Mod;
        x=x*x%Mod;
        y>>=1;
    }
    return ret;
	*/
}

int main() {
	while(cin >> n >> m >> k) {
		map<P,int> mp;
		int tmp = (n+1)/2;
		int ans = (tmp+1)*tmp/2;
		while(m--) {
			cin >> x >> y;
			if(x>n-1-x) x=n-1-x;
            if(y>n-1-y) y=n-1-y;
            if(x>y) swap(x,y);
            if(mp[make_pair(x,y)]==0){
                mp[make_pair(x,y)]=1;
                ans--;
            }
		}
		cout << pow(1LL*k,ans) << endl;
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int mod=1e8+7;
typedef __int64 INT;
map<pair<int,int>,int>mp;
int Pow(INT x,int nn){
    INT ret=1;
    while(nn){
        if(nn&1)
            ret=ret*x%mod;
        x=x*x%mod;
        nn>>=1;
    }
    return ret;
}
int main(){
    int n,m,k,x,y;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        mp.clear();
        int pted=0,cnt=0;
        while(m--){
            scanf("%d%d",&x,&y);
            if(x>n-1-x){ //坐标转化成三角形中的对称坐标
                x=n-1-x;
            }
            if(y>n-1-y){
                y=n-1-y;
            }
            if(x>y){
                swap(x,y);
            }
            if(mp[make_pair(x,y)]==0){
                mp[make_pair(x,y)]=1;
                pted++;//已经涂过色的
            }
        }
        int cc=(n+1)/2; 
        cnt=(cc+1)*cc/2;    //三角形中的总格子数
        INT ans=Pow((INT)k,(cnt-pted));
        printf("%I64d\n",ans);
    }
    return 0;
}
*/