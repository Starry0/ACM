#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#define ll long long
#define INF = 0x3f3f3f3f
using namespace std;
const int N = 1010;
const int M = 1010;
int day(int y, int m, int d) {
    if(m == 1 || m == 2) {
        m += 12;
        y --;
    }
    int w = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
    return w;
}
bool check(int y) {
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) return true;
    else return false;
}
int main() {
    int t, y, m, d;
    scanf("%d", &t);
    while(t--) {
        scanf("%d-%d-%d", &y, &m, &d);
        int x = day(y, m, d);
        bool flag = 0;
        if(m == 2 && d == 29) flag = 1;
        for(int i = y+1; ; i ++) {
            if(flag) {
                if(check(i) && day(i, m, d) == x) {
                    printf("%d\n",i);
                    break;
                }
            }else {
                if(day(i, m, d) == x) {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
