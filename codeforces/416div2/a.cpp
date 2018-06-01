#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	int ans = 0;
	for(;;){
		if(a <= 0 || b <= 0) break;
		if(ans%2){
			a-=ans;
		}else{
			b-=ans;
		}
		ans++;
	}
	if(a <= 0) cout << "Valera" << endl;
	else cout << "Vladik" << endl;
	return 0;
}