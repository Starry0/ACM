#include <iostream>
#include <stdio.h>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
    int s;
    cin >> s;
    int ans = INF;
    for(int i = 1; i <= sqrt(s); i ++) {
        if(s%i == 0)
        ans = min(ans,2*(i+s/i));
    }
    printf("%d\n",ans);
    return 0;
}
