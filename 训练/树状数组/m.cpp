#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 200006;
int n,tree[MAX],a[MAX],b[MAX],c[MAX],pos[MAX];
inline int iread(){
	int f = 1, x = 0; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch=getchar())f = ch=='-'?-1:1;
	for(; ch <= '9' && ch >= '0'; ch=getchar())x = x*10+ch-'0';
	return f*x;
}
inline void add(int x){
	while(x < MAX){
		tree[x] ++;
		x += lowbit(x);
	}
}
inline ll query(int x){
	ll sum = 0;
	while(x > 0){
		sum += (ll)tree[x];
		x -= lowbit(x);
	}
	return sum;
}
inline ll solve(int *x, int *y){
	ll res = 0;
	memset(tree,0,sizeof(tree));
	for(int i = 1; i <= n; i ++) pos[x[i]] = i;
	for(int i = n; i; i--) res += query(pos[y[i]]), add(pos[y[i]]);
	return res;
}
int main(){
	while(scanf("%d",&n)!=EOF){	
		for(int i = 1; i <= n; i ++)a[i] = iread();
		for(int i = 1; i <= n; i ++)b[i] = iread();
		for(int i = 1; i <= n; i ++)c[i] = iread();
		ll ans = 1ll*n*(n-1);
		ans -= solve(a,b)+solve(c,a)+solve(b,c);
		cout << ans/2 << endl;
	}
	return 0;
}


/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define lowbit(x) x&(-x)
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define mem(a) (memset(a,0,sizeof(a)))
int a[4][200006],pos[200006],vis[200006],n;
void add(int x){
    for(int i=x;i<=n;i+=lowbit(i)){
        vis[i]+=1;
    }
}
ll query(int x){
    ll ans=0;
    for(int i=x;i;i-=lowbit(i)){
        ans+=vis[i];
    }
    return ans;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        ll ans=0;
        for(int i=0;i<3;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<3;i++){
            memset(vis,0,sizeof(vis));
            for(int j=1;j<=n;j++){
                pos[a[i][j]]=j;
            }
            for(int j=n;j;j--){
                ans+=query(pos[a[(i+1)%3][j]]);
                add(pos[a[(i+1)%3][j]]);
            }
        }
        printf("%lld\n",(1ll*n*(n-1)-ans)>>1);
    }
    return 0;
}
*/