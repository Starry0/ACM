#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <cmath>
#define ll long long
#define INF = 0x3f3f3f3f
using namespace std;
const int N = 1010;
const int M = 1010;
int solve(int p) {
    int ans = 0;
    for(int i = 1; i <= sqrt(p); i ++) {
        if(p % i == 0) {
            ans += 2;
        }
    }
    int x = sqrt(p);
    if(x*x == p) ans--;
    return ans;
}
int main() {
    int t, p;
    cin >> t;
    while(t--) {
        cin >> p;
        printf("%d\n",solve(p-1));
    }
    return 0;
}
