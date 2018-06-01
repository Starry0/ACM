#include <iostream>
#include <string.h>
#include <math.h>
#define ll long long
using namespace std;
int main(){
	string s;
	while(cin>>s){
		if(s.length() > 10){
			cout << "TAT\n";
			continue;
		}
		ll ans = 0;
		for(int i = 0; i < s.length(); i++){
			ans = ans*10 + (ll)(s[i]-'0');
		}
		//cout << ans << endl;
		bool flag = false;
		for(int i = 1; i <= 5; i ++){
			ans = sqrt(ans);
			if(ans == 1LL){
				flag = true;
				cout << i << endl;
				break;
			}
		}
		if(!flag)cout << "TAT\n";
	}
	return 0;
}