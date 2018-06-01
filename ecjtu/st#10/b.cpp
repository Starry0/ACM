#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t,y,m,d;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&y,&m,&d);
        if((m+d)%2 ==0 || (m==9&&d==30) || (m==11&&d==30))
            puts("YES");
        else puts("NO");  
    }
    return 0;
}
