#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define fas ios::sync_with_stdio(false)
#define N 110
#define M 110
using namespace std;

int main() {
    fas;
    int n, MAX = 0, ans = 0;
    char str[300];
    cin>>n;
    while(cin>>str) {
        ans = 0;
        for(int i = 0; str[i]; i ++) {
            if(str[i] >= 'A' && str[i] <= 'Z'){
                ans ++;
            }
        }
        if(ans > MAX) MAX = ans;
    }
    if(ans > MAX) MAX = ans;
    printf("%d\n",MAX);
    return 0;
}
