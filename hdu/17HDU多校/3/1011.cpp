#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int t, num, ans = 0;
    for(cin>>t; t--; ){
        cin>>num;
        if(num <= 35) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
