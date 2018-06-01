#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,a,b;
	//scanf("%d",&n);
	cin>>n;
	while(n--){
		//scanf("%d%d",&a,&b);
		cin>>a>>b;
		for(ll c = 1; ; c ++){
			if(c!= b && __gcd(a,c) == b){
				//printf("%d\n",c);
				cout << c << endl;
				break;
			}
		}
	}
	return 0;
}