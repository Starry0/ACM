#include <bits/stdc++.h>
using namespace std;
char s[10105];
int main(){
    while(scanf("%s",s)!=EOF){
        if(s[0]=='0')
            break;
        int sum = 0;
        for(int i = 0; s[i]; i++){
            sum = sum*10 + s[i] - '0';
            sum %= 17;
        }
        printf("%d\n",sum?0:1);
    }
    return 0;
}
