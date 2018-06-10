#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], b[N];
int main() {
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    for(int i = 0; i < n; i ++) scanf("%d",&b[i]);
    for(int i = 0; i < n; i ++) {
        if(a[i]&&b[i]) {
            int tmp = min(a[i],b[i]);
            a[i] -= tmp;
            b[i] -= tmp;
        }
    }
    int id = n-1;
    for(int i = n-1; i >= 0; i --) {
        if(a[i]) {
            do{
                while(b[id] == 0 || id > i) id--;
                if(id < 0) break;
                ans += 1LL*min(a[i],b[id])*(i-id);
                if(b[id] >= a[i]) {
                    b[id] -= a[i];
                    a[i] = 0;
                } else {
                    a[i] -= b[id];
                    b[id] = 0;
                }
            }while(a[i] != 0);
        }
    }
    id = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i]) {
            do{
                while(b[id] == 0) id++;
                if(i >= id) ans += 1LL*min(a[i],b[id])*(i-id);
                else ans += 1LL*min(a[i],b[id])*(i+id);
                if(b[id] >= a[i]) {
                    b[id] -= a[i];
                    a[i] = 0;
                } else {
                    a[i] -= b[id];
                    b[id] = 0;
                }
            }while(a[i] != 0);
        }
    }
    cout << ans << endl;
    return 0;
}
