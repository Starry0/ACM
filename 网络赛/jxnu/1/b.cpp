#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s;
    while(cin >> s){
        int ans = 0, flag = 0;
        int len = s.length();
        for(int i = 0; i < len-1; i ++){
            if(s[i] == 'Y' && s[i+1] == 'S'){
                ans ++;
            }
        }
        for(int i = 0; i < len-2; i ++){
            if(s[i] == 'Y' && s[i+1] == 'Y' && s[i+2] =='Y'){
                flag = 1;
            }
            if(s[i] == 'S' && s[i+1] =='S' && s[i+2] == 'S'){
                flag = 1;
            }
        }
        if(flag) ans++;
        cout << ans << endl;
    }
    return 0;
}
