#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    for(int i = 1; i <= 9; i ++) a[i] = i;
    cin >> n;
    do{
        for(int i = 2; i <= 9; i ++) {
            for(int j = 2; j <= 9; j ++) {
                int A = 0, B = 0, C = 0;
                if(i==j) continue;
                if(i < j){
                    int k = 1;
                    while(k < i) A = A*10+a[k++];
                    while(k < j) B = B*10+a[k++];
                    while(k < 10) C = C*10+a[k++];
                    if(A*B-C == n) {
                        ans++;
                    }
                }
            }
        }
    }while(next_permutation(a+1,a+1+9));
    cout << ans << endl;
    return 0;
}
