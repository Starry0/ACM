// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// int a[1010],vis[1010];
// int main(){
//     int n, num;
//     cin >> n;
//     for(int i = 0; i < n; i ++){
//         cin >> a[i];
//     }
//     sort(a,a+n);
//     int ans = 0;
//     int cnt = 0;
//     while(true){
//         if(cnt == n)break;
//         int flag = 0,a1,a2;
//         for(int i = 0; i < n; i ++){
//             if(!vis[i] && !flag){
//                 a1 = a[i];
//                 flag = vis[i] = 1;
//                 cnt++;
//             }else if(!vis[i] && a1 < a[i] && flag){
//                 ans++;
//                 vis[i] = true;
//                 cnt++;
//                 a1 = a[i];
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
//

#include <iostream>
using namespace std;
int t,i,a[1001],n,k;
main(){
    cin>>n;
    while(i++<n)
    cin>>t,k=(++a[t]>k?a[t]:k);
    cout<<n-k;
}
