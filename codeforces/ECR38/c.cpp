#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int main() {
    int t, x;
    cin >> t;
    while(t--) {
        cin >> x;
        if(x == 0) cout << "1 1\n";
        else if(x == 1) cout << "-1\n";
        else {
            int n = sqrt(x)+1, flag = 0;
            while(true){
                if(n*n-(n/2)*(n/2) > x) break;
                for(int i = 2; i <= n; i ++) {
                    int m = n/i;
                    if(x == n*n-m*m ) {
                        cout << n << ' ' << i << endl;
                        flag = 1;
                        break;
                    } else if(n*n-m*m > x) break;
                }
                if(flag)break;
                n++;
            }
            if(!flag) cout << "-1\n";
        }
    }
    return 0;
}
