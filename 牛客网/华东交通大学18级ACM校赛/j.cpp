#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[11];
int main() {
    while(cin>>a[0]) {
        for(int i = 1; i < 10; i ++) cin >> a[i];
        int pos = 3;
        for(int i = 0; i < 10; i ++) {
            if(a[i] == 1) {
                pos = min(7, pos+1);
            } else if(a[i] == 7) {
                pos = max(1, pos-1);
            }
        }
        if(pos == 7)printf("666\n");
        else printf("777\n");
    }
    return 0;
}
