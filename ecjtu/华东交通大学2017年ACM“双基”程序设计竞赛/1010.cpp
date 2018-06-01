#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s;
    while(cin >> s){
        if(s.length() > 10){
            cout << "QAQ\n";
            continue;
        }
        ll ans = 0;
        for(int i = 0; i < s.length(); i++){
            ans = ans*10 + (ll)(s[i]-'0');
        }
		if(ans == 1) {
			printf("0\n");
			continue;
		}
        bool flag = false;
        for(int i = 1; i <= 5; i ++){
            ans = sqrt(ans);
            if(ans == 1LL){
                flag = true;
                cout << i << endl;
                break;
            }
        }
        if(!flag) printf("QAQ\n");
    }
    return 0;
}