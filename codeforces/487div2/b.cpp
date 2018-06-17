#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
char str[N];
int n, p;
int main() {
    cin >> n >> p >> str;
    bool flag = true;
    for(int i = 0; i < n; i ++) {
        if(i >= n-p) {
            if(str[i] == '.') str[i] = '0';
            continue;
        }
        if(str[i] != '.' && str[i+p] != '.') {
            if(str[i] != str[i+p]) flag = false;
        } else if(str[i] == '.' && str[i+p] != '.') {
            str[i] = 1-(str[i+p]-'0')+'0';
            flag = false;
        } else if(str[i] != '.' && str[i+p] == '.') {
            str[i+p] = 1-(str[i]-'0')+'0';
            flag = false;
        } else if(str[i] == '.' && str[i+p] == '.') {
            str[i] = '0'; str[i+p] = '1';
            flag = false;
        }
    }
    if(flag) printf("No\n");
    else cout << str << endl;
    return 0;
}
// 12345678910
// 1.0.1.1000
// 1001101000
