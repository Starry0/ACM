#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)
 
typedef long long ll;
const int maxn = 2e5+1;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
 
int t1[maxn],t2[maxn],c[maxn];
 
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
 
void da(int *str,int *sa,int *Rank,int *height,int n,int m)
{
    n++;
    int i,j,p,*x=t1,*y=t2;
    for(i=0; i<m; i++) c[i]=0;
    for(i=0; i<n; i++) c[x[i]=str[i]]++;
    for(i=1; i<m; i++) c[i]+=c[i-1];
    for(i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
    for(j=1; j<=n; j<<=1)
    {
        p=0;
        for(i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++)
        {
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        }
        for(i=0; i<m; i++)  c[i]=0;
        for(i=0; i<n; i++)  c[x[y[i]]]++;
        for(i=1; i<m; i++)  c[i]+=c[i-1];
        for(i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1,x[sa[0]]=0;
        for(i=1; i<n; i++)
        {
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
        if(p>=n) break;
        m=p;
    }
    int k=0;
    n--;
    for(i=0; i<=n; i++) Rank[sa[i]]=i;
    for(i=0; i<n; i++)
    {
        if(k) k--;
        j=sa[Rank[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[Rank[i]]=k;
    }
}
 
 
int Rank[maxn],height[maxn],sa[maxn];
char str[maxn];
int r[maxn];
 
 
int dp[maxn][30];
 
void initRMQ(int n)
{
    for(int i=0;i<n;i++) dp[i][0]=height[i];
    for(int j=1;(1<<j)<=n;j++)
    for(int i=0;i+(1<<j)-1<n;i++)
    {
        dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
}
 
int len;
 
int lcp(int l,int r)
{
    if(l==r)  return len-sa[r];
    /*l=Rank[l],r=Rank[r];
    if(l>r) swap(l,r);*/
    l++;
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
 
int main()
{
    int a, b;
    rush()
    {
        scanf("%s%d%d",str,&a,&b);b++;
        int n=strlen(str);
        len=n;
        for(int i=0; i<n; i++)
        {
            r[i]=str[i]-'A'+1;
        }
        r[n]=0;
        da(r,sa,Rank,height,n,30);           
        initRMQ(n+1);                      
        ll ans1=0, ans2 = 0;
        for(int i=1; i+a-1<=n; i++)         
        {
            ans1+=lcp(i,i+a-1);
            if(i>1) ans1-=lcp(i-1,i+a-1);
            if(i+a<=n) ans1-=lcp(i,i+a);
            if(i>1&&i+a<=n) ans1+=lcp(i-1,i+a);
        }
        for(int i=1; i+b-1<=n; i++)         
        {
            ans2+=lcp(i,i+b-1);
            if(i>1) ans2-=lcp(i-1,i+b-1);
            if(i+b<=n) ans2-=lcp(i,i+b);
            if(i>1&&i+b<=n) ans2+=lcp(i-1,i+b);
        }
        printf("%I64d\n",ans1-ans2);
    }
    return 0;
}
