#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i <= sqrt(n/2); i ++) {
        int x = n - i*i;
        int y = sqrt(x);
        if(y * y == x) {
            printf("%d %d\n",i, y);
            ans ++;
        }
    }
    if(!ans)printf("No Solution\n");
    return 0;
}
