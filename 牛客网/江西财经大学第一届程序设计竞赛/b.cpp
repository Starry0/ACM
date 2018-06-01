#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
const int N = 11;
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool ok(int y) {
    if((y%4==0&&y%100!=0) || y%400==0) return true;
    else return false;
}
bool ok1(int x) {
    while(x) {
        if(x%10 == 4) return true;
        x /= 10;
    }
    return false;
}
int main() {
    int t, y, m, d;
    cin >> t;
    while(t--) {
        scanf("%d-%d-%d",&y,&m,&d);
        int ans = 0;
        if(y == 2018) {
            for(int i = m; i <= 4; i ++) {
                for(int j = 1; j <= day[i]+(i==2&&ok(y)?1:0); j ++) {
                    if(i == 4 && j == 21) break;
                    if(ok1(i) || ok1(j)) continue;
                    ans++;
                }
            }
        } else {
            for(int i = m; i <= 12; i ++) {
                for(int j = 1; j <= day[i]+(i==2&&ok(y)?1:0); j ++) {
                    if(i == m && j < d) continue;
                    if(ok1(y) || ok1(i) || ok1(j)) continue;
                    ans++;
                }
            }
            for(int i = y+1; i < 2018; i ++) {
                for(int j = 1; j <= 12; j ++) {
                    for(int k = 1; k <= day[j]+(j==2&&ok(i)?1:0); k ++) {
                        if(ok1(i) || ok1(j) || ok1(k)) continue;
                        ans++;
                    }
                }
            }
            for(int i = 1; i <= 4; i ++) {
                for(int j = 1; j <= day[i]; j ++) {
                    if(ok1(i) || ok1(j)) continue;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
