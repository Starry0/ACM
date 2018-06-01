#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 1e5+10;
char str[MAX];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(str,0,sizeof(str));
		int n,p;
		cin>>n>>p;
		p--;
		cin>>str;
		ll ans = 0;
		int Min = MAX*10, Max = -1,flag = 0;
		for(int i = 0; i < n/2; i ++){
			if(str[i] != str[n-i-1]){
				int cnt = abs(str[i]-str[n-i-1]);
				ans+= min(cnt,26-cnt);
				Min = min(Min,i);
				Max = max(Max,i);
				flag = 1;
			}
		}
		if(!flag){
			cout << 0 << endl;
			continue;
		}
		if(p >= n/2)p = n-p-1;
		if(p <= Min){
			cout <<ans+ Max-p << endl;
		}else if(Min < p && p < Max){
			cout << ans+Max-Min + min((p-Min),(Max-p)) << endl;;
		}else if(p >= Max){
			cout << ans+p-Min << endl;
		}
	}
	return 0;
}


