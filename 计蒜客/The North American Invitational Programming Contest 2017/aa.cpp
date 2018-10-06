#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#pragma comment(linker, "/stck:1024000000,1024000000")
#pragma GCC diagnostic error "-std=c++11"
#define lowbit(x) (x&(-x))
#define max(x,y) (x>=y?x:y)
#define min(x,y) (x<=y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define pi acos(-1.0)
#define ei exp(1)
#define PI 3.1415926535897932384626433832
#define ios() ios::sync_with_stdio(true)
#define INF 0x3f3f3f3f
#define mem(a) ((a,0,sizeof(a)))
typedef long long ll;
struct node
{
    int l,r,val;
    int type,mid;
    void init(){
        if(l>=0) type=1,mid=-r;
        else type=0,mid=l-r;
    }
    bool operator<(const node a) const&{
        if(a.type!=type) return a.type<type;
        if(a.type==1) return a.mid>mid;
        return a.mid<mid;
    }
}e[300];
int n,k,ans=0,dp[90006],vis[90006];
char s[306];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&s);
        k=strlen(s);
        for(int j=0;j<k;j++){
            s[j]=='('?e[i].l++:e[i].l--;
            e[i].r=min(e[i].r,e[i].l);
        }
        e[i].val=k;
        e[i].init();
        ans+=k;
        printf("%d %d %d\n",e[i].l,e[i].mid,e[i].r);
    }
    sort(e,e+n);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<ans;j++)
            vis[j]=dp[j];
        for(int j=0;j<ans;j++)
            if(j+e[i].r>=0 && vis[j]>=0)
                dp[j+e[i].l]=max(dp[j+e[i].l],vis[j]+e[i].val);
    }
    printf("%d\n",dp[0]);
    return 0;
}
