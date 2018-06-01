#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define ll long long
using namespace std;
const int N = 3e5+10;
char str[N];
int main(){
    scanf("%s",str);
    ll ans = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i ++) {
        if((str[i]-'0')%4==0) ans++;
    }
    for(int i = 0; i < len-1; i ++) {
        int tem = 0;
        for(int j = i;j <= i+1; j ++) {
            tem = tem*10 + (str[j]-'0');
        }
        if(tem%4==0) ans+=(i+1);
    }
    cout << ans << endl;
    return 0;
}
