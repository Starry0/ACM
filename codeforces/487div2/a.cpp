#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
char str[N];
int main() {
    cin >> str;
    int len = strlen(str);
    for(int i = 1; i < len-1; i ++) {
        if(str[i] != '.' && str[i-1] != '.' && str[i+1] != '.') {
            if(str[i] != str[i-1] && str[i-1] != str[i+1] && str[i] != str[i+1]) {
                return 0*printf("Yes\n");
            }
        }
    }
    printf("No\n");
    return 0;
}
