// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #define ll long long
// #define lson l,m,rt<<1
// #define rson m+1,r,rt<<1|1
// using namespace std;
// const int MAX = 10010;
// int n,m,str,x;
// int tree[MAX<<2];
// void Push(int rt) {
//     tree[rt] = tree[rt<<1] + tree[rt<<1|1];
// }
// void build(int l, int r, int rt) {
//     if(l == r) {
//         scanf("%d",&x);
//         tree[rt] = str-x;
//         return ;
//     }
//     int m = (l+r)>>1;
//     build(lson);
//     build(rson);
//     Push(rt);
// }
// ll query(int l, int r, int rt, int LL, int RR) {
//     if(LL <= l && r <= RR) {
//         return tree[rt];
//     }
//     ll sum = 0;
//     int m = (l+r)>>1;
//     if(m >= LL) sum += 1LL*query(lson,LL,RR);
//     if(m < RR) sum += 1LL*query(rson,LL,RR);
//     return sum;
// }
// int main() {
//     std::ios::sync_with_stdio(false);
//     while(cin>>n>>m>>str) {
//         memset(tree,0,sizeof(tree));
//         build(1,n,1);
//         ll ans = 0;
//         for(int i = 1; i <= m; i ++) {
//             int L, R;
//             scanf("%d%d",&L,&R);
//             ll xx = query(1,n,1,L,R);
//             if(xx > 0) ans += xx;
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }
//
//
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <set>
// #define ll long long
// using namespace std;
// int n, m;
// const int MAX = 20010;
// ll sum[MAX], str;
//
// int main() {
//     std::ios::sync_with_stdio(false);
//     while(cin>>n>>m>>str){
//         memset(sum,0,sizeof(sum));
//         set<pair<int,int> > st;
//         ll x;
//         for(ll i = 1; i <= n; i ++) {
//             cin>>x;
//             sum[i] += sum[i-1] + str - x;
//         }
//         ll ans = 0;
//         while(m--) {
//             int l, r;
//             cin>>l>>r;
//             if(st.count(make_pair(l,r)))continue;
//             st.insert(make_pair(l,r));
//             ll x = sum[r] - sum[l-1];
//             if(x > 0LL) ans += x;
//         }
//         cout << ans << endl;
//         st.clear();
//     }
//     return 0;
// }
//
//
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <set>
// #define ll long long
// #define lowbit(x) x&(-x)
// using namespace std;
// const int MAX = 10010;
// int n, m, str;
// ll sum[MAX];
// void add(int x, ll q){
//     while(x < MAX) {
//         sum[x] += q;
//         x += lowbit(x);
//     }
// }
// ll query(int x) {
//     ll sum1 = 0;
//     while(x > 0) {
//         sum1 += sum[x];
//         x-=lowbit(x);
//     }
//     return sum1;
// }
// int main() {
//     while(scanf("%d%d%d",&n,&m,&str) != EOF) {
//         ll x;
//         set<pair<int,int> >st;
//         st.clear();
//         memset(sum,0,sizeof(sum));
//         for(int i = 1; i <= n; i ++) {
//             scanf("%lld",&x);
//             add(i,1LL*str-x);
//         }
//         ll ans = 0;
//         while(m--) {
//             int l, r;
//             scanf("%d%d",&l,&r);
//             if(st.count(make_pair(l,r)))continue;
//             ll xx = query(r) - query(l-1);
//             if(xx > 0LL) ans += xx;
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }



// #include <iostream>
// #include <cstring>
// #include <string>
// #include <cstdio>
// #define LL long long
// #define N 11000
// using namespace std;
// int num[N];
// int main() {
//     cin.sync_with_stdio(false);
//     int n, m;
//     int strong;
//     int a, b, c;
//     while (cin >> n >> m >> strong) {
//         num[0] = 0;
//         for (int i = 1; i <= n; i++) {
//             cin >> num[i];
//             num[i] = strong - num[i];
//             num[i] += num[i - 1];
//         }
//         int sum = 0;
//         for (int i = 0; i < m; i++) {
//             cin >> a >> b;
//             c = num[b] - num[a - 1];
//             if (c > 0) {
//                 sum += c;
//             }
//         }
//         cout << sum << endl;
//     }
//     return 0;
// }

//
// #include <iostream>
// #include <string.h>
// using namespace std;
// const int MAX = 10010;
// int sum[MAX];
// int main() {
//     std::ios::sync_with_stdio(false);
//     int n,m,str;
//     while(cin>>n>>m>>str) {
//         int num;
//         for(int i = 1; i <= n; i ++) {
//             cin >> num;
//             sum[i] = sum[i-1] + str - num;
//         }
//         int ans = 0;
//         while(m--) {
//             int l, r;
//             cin >> l >> r;
//             int x = sum[r] - sum[l-1];
//             if(x > 0) ans += x;
//         }
//         cout << ans << endl;
//         memset(sum,0,sizeof(sum));
//     }
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 10010;
ll sum[MAX], str;
int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    while(cin>>n>>m>>str) {
        ll x;
        for(int i = 1; i <= n; i ++) {
            cin >> x;
            sum[i] = sum[i-1] + str - x;
        }
        ll ans = 0;
        while(m--) {
            int l, r;
            cin >> l >> r;
            ll y = sum[r] - sum[l-1];
            if(y > 0) ans += y;
        }
        cout << ans << endl;
        memset(sum,0,sizeof(sum));
    }
}
