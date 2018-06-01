#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[110];
int main() {
    cin >> str;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; str[i]; i ++) {
        if(str[i] == '-') ans1++;
        else ans2 ++;
    }
    if(ans1 == 0 || ans2 == 0) return 0*printf("YES\n");
    if(ans1 %ans2 == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
