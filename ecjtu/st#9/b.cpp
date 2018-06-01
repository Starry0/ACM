// // #include <iostream>
// // #include <stdio.h>
// // #include <string.h>
// // #include <algorithm>
// // #define lson l,m,rt<<1
// // #define rson m+1,r,rt<<1|1
// // #define ll long long
// // using namespace std;
// // const int MAX = 100010;
// // const ll INF = 1000000000000;
// // ll tree[MAX<<2];
// // int b[MAX],d[MAX],q[MAX];
// // void Push(int rt){
// //     tree[rt] = min(tree[rt<<1|1],tree[rt<<1]);
// // }
// // void build(int l, int r, int rt) {
// //     tree[rt] = INF;
// //     if(l == r) return ;
// //     int m = (l+r) >> 1;
// //     build(lson);
// //     build(rson);
// // }
// // void update(int l, int r, int rt, int p, ll x){
// //     if(l == r){
// //         tree[rt] = x;
// //         return ;
// //     }
// //     int m = (l+r) >> 1;
// //     if(p <= m) update(lson,p,x);
// //     else update(rson,p,x);
// //     Push(rt);
// // }
// // ll query(int l, int r, int rt, int LL, int RR){
// //     if(LL <= l && r <= RR){
// //         ll xx = tree[rt];
// //         tree[rt] = INF;
// //         return xx;
// //     }
// //     int m = (l+r)>>1;
// //     ll Min = INF;
// //     if(LL <= m) Min = min(Min,query(lson,LL,RR));
// //     if(m < RR) Min = min(Min,query(rson,LL,RR));
// //     Push(rt);
// //     return Min;
// // }
// // int main() {
// //     int n, m;
// //     while(scanf("%d %d",&n,&m)!=EOF){
// //         int Ma = -1,Mb = -1;
// //         for(int i = 1; i <= n; i ++){
// //             scanf("%d",&b[i]);
// //             Mb = max(Mb,b[i]);
// //         }
// //         for(int i = 1; i <= m; i ++){
// //             scanf("%d",&d[i]);
// //             Ma = max(Ma,d[i]);
// //         }
// //         for(int i = 1; i <= m; i ++) scanf("%d",&q[i]);
// //         if(Mb > Ma || n > m) printf("NO\n");
// //         else {
// //             memset(tree,0,sizeof(tree));
// //             build(1,MAX-1,1);
// //             for(int i = 1; i <= m; i ++) {
// //                 update(1,MAX-1,1,d[i],1LL*q[i]);
// //             }
// //             ll ans = 0;
// //             sort(b+1,b+1+n);
// //             bool flag = false;
// //             for(int i = n; i > 0; i --) {
// //                 ll y =  query(1,MAX-1,1,b[i],MAX-1);
// //             //    cout << b[i] << ' ' << y << endl;
// //                 if(y == INF){
// //                     flag = true;break;
// //                 }
// //                 ans += y;
// //             }
// //         //    cout << query(1,MAX-1,1,3,3)<<endl;
// //             if(flag) printf("NO\n");
// //             else printf("%lld\n",ans);
// //         }
// //     }
// //     return 0;
// // }
//
//
// #include <stdio.h>
// #include <algorithm>
// #include <string.h>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <math.h>
// using namespace std;
// const int MAXN=100010;
// int B[MAXN];
// struct Node
// {
//     int D,P;
// }node[MAXN];
// bool cmp1(Node a,Node b)
// {
//     return a.D<b.D;
// }
//
// struct cmp
// {
//     bool operator ()(int x, int y)
//     {
//         return x > y;// x小的优先级高
//       //也可以写成其他方式，如： return p[x] > p[y];表示p[i]小的优先级高
//     }
// };
// priority_queue<int, vector<int>, cmp>q;//定义方法
//
//
// int main()
// {
//     int n,m;
//     while(scanf("%d%d",&n,&m)==2)
//     {
//         while(!q.empty())q.pop();
//         for(int i=0;i<n;i++)scanf("%d",&B[i]);
//         for(int i=0;i<m;i++)scanf("%d",&node[i].D);
//         for(int i=0;i<m;i++)scanf("%d",&node[i].P);
//         if(n>m)
//         {
//             printf("No\n");
//             continue;
//         }
//         sort(B,B+n);
//         sort(node,node+m,cmp1);
//         int t=m-1;
//         bool flag=true;
//         long long ans=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             while(t>=0 && node[t].D>=B[i])
//             {
//                 q.push(node[t].P);
//                 t--;
//             }
//             if(q.empty())
//             {
//                 flag=false;
//                 break;
//             }
//             ans+=q.top();
//             q.pop();
//         }
//         if(flag)cout<<ans<<endl;        //printf("%d\n",ans);
//         else printf("No\n");
//     }
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
const int MAX = 100010;
int b[MAX];
struct Nod{
    int d,q;
}nod[MAX];
bool cmp(Nod a, Nod b) {
    return a.d < b.d;
}
int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i = 0; i < n; i ++) scanf("%d",&b[i]);
        for(int i = 0; i < m; i ++) scanf("%d",&nod[i].d);
        for(int i = 0; i < m; i ++) scanf("%d",&nod[i].q);
        if(n > m) {
            printf("No\n");
            continue;
        }
        sort(b,b+n);
        sort(nod,nod+m,cmp);
        priority_queue<int, vector<int>, greater<int> >que;
        int k = m-1;
        bool flag = true;
        ll ans = 0;
        for(int i = n-1; i >= 0; i --) {
            while(k >= 0 && nod[k].d >= b[i]){
                que.push(nod[k].q);
                k--;
            }
            if(que.empty()){
                flag = false;
                break;
            }
            ans += que.top();
            que.pop();
        }
        if(flag)printf("%lld\n",ans);
        else printf("No\n");
    }
    return 0;
}
