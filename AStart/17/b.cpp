//下面是错的
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #define ll long long
// using namespace std;
// const ll N = 3010;
// ll fa[N];
// ll edge[N];
// ll find(ll x) {
//     fa[x] = (fa[x] == x ? x: find(fa[x]));
// }
// void unite(ll x, ll y) {
//     x = find(x);
//     y = find(y);
//     if(x > y) fa[x] = y;
//     else fa[y] = x;
// }
// int main() {
//     ll n, m;
//     while(scanf("%lld %lld", &n, &m) != EOF) {
//         memset(edge, 0, sizeof(edge));
//         for(ll i = 1; i <= n; i ++) fa[i] = i;
//         ll ans = 0;
//         for(ll i = 1; i <= m; i ++) {
//             ll u, w, v;
//             scanf("%d%d%d",&u,&v,&w);
//             edge[u] += 1LL*w;
//             edge[v] += 1LL*w;
//             if(find(u) != find(v)) {
//                 unite(u, v);
//                 ans ++;
//             }
//         }
//         if(ans != n-1) {
//             printf("0\n");
//             continue;
//         }
//         ll sum = edge[1];
//         for(ll i = 2; i <= n; i ++) {
//             if(sum > edge[i]) sum = edge[i];
//         }
//         printf("%lld\n",sum);
//     }
//     return 0;
// }
//

//这个是对的
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <vector>
// #include <map>
// #define ll long long
// using namespace std;
// const int N=1e5+10;
// map<int,int>mp1,mp;
// int fa[2*N], n,m;
// vector<int>vs[N];
// int find(int x) {
//     if(x==fa[x])
//         return x;
//     return fa[x]=find(fa[x]);
// }
// int edge[3010][3010];
// void unite(int x,int y) {
//     x=find(x);
//     y=find(y);
//     if(x != y) {
//         fa[x] = y;
//     }
// }
// void init() {
//     for(int i = 1; i <= n; i ++) {
//         vs[i].clear();
//         fa[i] = i;
//     }
//     memset(edge, 0, sizeof(edge));
//     mp1.clear();
//     mp.clear();
// }
// inline int read() {
//     int x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f;
// }
// int main(){
//     while(scanf("%d%d",&n,&m) != EOF){
//         init();
//         for(int i = 1; i <= m; i ++){
//             int s, t, w;
//             s = read(); t = read(); w = read();
//             if(edge[s][t]) {
//                 edge[s][t] += w;
//                 edge[t][s] += w;
//             }else {
//                 edge[s][t] = w;
//                 edge[t][s] = w;
//             }
//             unite(s,t);
//         }
//         for(int i = 1; i <= n; i ++) {
//             for(int j = 1; j <= n; j ++) {
//                 if(i == j) continue;
//                 mp1[i] += (edge[i][j]);
//             }
//         }
//         for(int i = 1; i <= n; i++) {
//             if(mp[find(i)]) {
//                 mp[find(i)]=min(mp[find(i)],mp1[i]);
//             }else {
//                 mp[find(i)]=mp1[i];
//             }
//             vs[find(i)].push_back(i);
//         }
//         ll ans = 0;
//         for(int i=1;i<=n;i++){
//             if(find(i)==i){
//                 if(vs[i].size()>1){
//                     ans += mp[i];
//                 }
//             }
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }
//
//这个也答案错误了
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <vector>
// #include <queue>
// using namespace std;
// typedef long long ll;
// const int MAX = 3010;
// const int M = 100010;
// const ll INF = 1LL<<62;
// ll fa[MAX];
// ll find(ll x) {
//     return fa[x] = (fa[x] ==x ? x: find(fa[x]));
// }
// void unite(ll x, ll y) {
//     x = find(x);
//     y = find(y);
//     if(x < y) fa[y] = x;
//     else fa[x] = y;
// }
// struct Nod {
//     ll to, cap, rev;
// };
// vector<Nod> G[MAX];
// ll level[MAX], iter[MAX];
// void add_edge(ll from, ll to, ll cap) {
//     G[from].push_back((Nod){to,cap,(ll)G[to].size()});
//     G[to].push_back((Nod){from,0,(ll)G[from].size()-1});
// }
// void bfs(ll s) {
//     memset(level, -1, sizeof(level));
//     queue<ll> que;
//     level[s] = 0;
//     que.push(s);
//     while(!que.empty()) {
//         ll v = que.front(); que.pop();
//         for(ll i = 0; i < G[v].size(); i ++) {
//             Nod &e = G[v][i];
//             if(e.cap > 0 && level[e.to] < 0){
//                 level[e.to] = level[v] + 1;
//                 que.push(e.to);
//             }
//         }
//     }
// }
// ll dfs(ll v, ll t, ll f) {
//     if(v == t) return f;
//     for(ll &i = iter[v]; i < G[v].size(); i ++) {
//         Nod &e = G[v][i];
//         if(e.cap > 0 && level[v] < level[e.to]) {
//             ll d = dfs(e.to, t, min(f,e.cap));
//             if(d > 0) {
//                 e.cap -= d;
//                 G[e.to][e.rev].cap += d;
//                 return d;
//             }
//         }
//     }
//     return 0;
// }
// ll max_flow(ll s, ll t) {
//     ll flow = 0;
//     while(1) {
//         bfs(s);
//         if(level[t] < 0) return flow;
//         memset(iter,0,sizeof(iter));
//         ll f;
//         while((f = dfs(s, t, INF)) > 0) flow += f;
//     }
// }
// int main() {
//     ll n, m;
//     while(scanf("%lld%lld",&n,&m)!=EOF) {
//         for(ll i = 1; i <= n; i ++) fa[i] = i, G[i].clear();
//         // for(ll i = 1; i <= M*2; i ++) G[i].clear();
//         for(int i = 1; i <= m; i ++) {
//             ll u, v, w;
//             scanf("%lld %lld %lld", &u, &v, &w);
//             add_edge(u, v, w);
//             add_edge(v, u, w);
//             unite(u,v);
//         }
//         int ans = 0;
//         for(ll i = 1; i <= n; i ++) {
//             if(fa[i] == i) ans++;
//         }
//         if(ans > 1){
//             printf("0\n");
//             continue;
//         }
//         // for(ll i = 0; i < G[1].size(); i ++) {
//         //     Nod &e = G[1][i];
//         //     printf("%lld %lld %lld \n",e.to,e.cap,e.rev);
//         // }
//         printf("%lld\n",max_flow(1,n));
//     }
//     return 0;
// }
