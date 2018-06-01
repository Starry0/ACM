// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int N = 2e5+10;
// ll k, len, x;
// vector<ll> vs[N];
// map<ll,int> mp[N];
// int main() {
//     // cin >> k;
//     scanf("%d", &k)
//     for(int i = 1; i < k; i ++) {
//         scanf("%d", &len);
//         ll sum = 0;
//         for(int j = 0; j < len; j ++) {
//             scanf("%d", &x);
//             sum += x;
//             vs[i].push_back(x);
//         }
//         for(int j = 0; j < len; j ++) {
//             mp[i][sum-vs[i][j]] = 1;
//         }
//     }
//
//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll k, len, x;
struct Nod{
    ll sum, id, kk;
    Nod() {
        id = kk = sum = -1;
    }
}nod[N];
ll a[N];
bool cmp(const Nod &a, const Nod &b) {
    if(a.sum != b.sum ) return a.sum < b.sum;
    else return a.kk < b.kk;
}
int main() {
    int n = 0;
    scanf("%lld", &k);
    for(int i = 1; i <= k; i ++) {
        scanf("%lld", &len);
        ll sum = 0;
        for(int j = 1; j <= len; j ++) {
            scanf("%lld", &a[j]);
            sum += a[j];
        }
        for(int j = 1; j <= len; j ++) {
            nod[n].sum = sum - a[j];
            nod[n].kk = i;
            nod[n++].id = j;
        }
    }
    sort(nod,nod+n,cmp);
    // for(int i = 0; i < n; i ++) {
    //     printf("%lld %lld %lld\n",nod[i].sum,nod[i].kk,nod[i].id);
    // }
    int l = 0, r = 1;
    while(r < n) {
        while(nod[l].sum != nod[r].sum && r+1 < n) {
            l++;r++;
        }
        while(nod[l].sum == nod[r].sum && nod[r].sum == nod[r+1].sum) r++;
        if(nod[l].sum == nod[r].sum && nod[l].kk != nod[r].kk) {
            printf("YES\n");
            return 0*printf("%lld %lld\n%lld %lld\n",nod[l].kk,nod[l].id,nod[r].kk,nod[r].id);
        }
        r += 2;
        l = r - 1;
    }
    printf("NO\n");
    return 0;
}
