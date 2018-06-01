#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        bool flag = true;
        int index = 0, ans = 1;
        for(int i = 1; i < s.length(); i ++) {
            if(s[i] >= 'A' && s[i] <= 'Z' && i == index + 1) {
                flag = false;
                break;
            } else if(s[i] >= 'A' && s[i] <= 'Z') index = i, ans++;
        }
        if(ans == 1||!flag || (index==s.length()-1)) cout << s << endl;
        else {
            for(int i = 0; i < s.length(); i ++) {
                if(s[i] >= 'A' && s[i] <= 'Z' && i != 0) {
                    printf("_%c",s[i]+32);
                } else if(s[i] >= 'A' && s[i] <= 'Z' && i == 0){
                    printf("%c",s[i]+32);
                }else cout << s[i];
            }
            cout << endl;
        }
    }
    return 0;
}
