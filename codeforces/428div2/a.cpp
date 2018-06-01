#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n, k, x, ans = 0, sum = 0, Min = -1;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        if(x > 8) {
            sum += x - 8;
            ans += 8;
        }else {
            int y = min(8, x + sum);
            ans += y;
            sum = sum + x - y;
        }
        if(ans >= k){
            Min = i;
            break;
        }
    }
    printf("%d\n",Min);
    return 0;
}
