// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int N = 110;
// int a[N];
// int main() {
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i ++) cin >> a[i], a[i] %=2;
//     if(n%2==1) {
//         if(a[0]==1 && a[n-1]==1) printf("Yes\n");
//         else printf("No\n");
//     } else {
//         if(a[0]==0 || a[n-1]==0) return 0*printf("No\n");
//         int ans = 0, sta = 0;
//         for(int i = 1; i < n-1; i ++) {
//             if(a[i] == 1 && a[i+1]==1) {
//                 ans++;i++;
//                 sta=i;
//             }
//         }
//         if(sta != n-1) ans++;
//         if(ans >= 3) printf("Yes\n");
//         else printf("No\n");
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >>a[i];
    if(n%2==0 || a[1] %2 == 0 || a[n]%2==0) {
        return 0*printf("No\n");
    }
    printf("Yes\n");
    return 0;
}