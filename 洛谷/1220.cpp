/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 55;
int dp[N*10][N*10][2];
int a[N], w[N], n, m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d",&w[i],&a[i]);
        a[i] += a[i-1];
    }
    memset(dp, INF, sizeof(dp));
    dp[m][m][0]=dp[m][m][1]=0;
    for(int j = m; j <= n; j ++)
        for(int i = j-1; i; i --) {
            dp[i][j][0] = min(dp[i+1][j][0] + (a[n]-(a[j]-a[i])) * (w[i+1]-w[i]),
                        dp[i+1][j][1]+(a[n]-(a[j]-a[i])) * (w[j]-w[i]));
            dp[i][j][1] = min(dp[i][j-1][1]+(a[n]-(a[j-1]-a[i-1])) * (w[j]-w[j-1]),
                        dp[i][j-1][0]+(a[n]-(a[j-1]-a[i-1])) * (w[j]-w[i]));
    }
    printf("%d\n",min(dp[1][n][0],dp[1][n][1]));
    return 0;
}
*/


#include<iostream>
using namespace std;
int a[55];  //位置
int b[55];  //功率
bool c[55];
int n,d;
int ans=99999999;
int w;//此秒总功率
void hh(int nw,int now,int ans1,int nn)
{	if(ans1>ans) return ;
	if(nn==0){
		ans=min(ans,ans1);
		return;
	}
	int i;
	i=now-1;
	while(c[i]==false&&i>0) i--;
	if(c[i]&&i>0){
			c[i]=false;
			hh(nw-b[i],i,nw*(a[now]-a[i])+ans1,nn-1);
			c[i]=true;
		    }
	i=now+1;
	while(c[i]==false&&i<=n)i++;
	if(c[i]&&i<=n){
			c[i]=false;
			hh(nw-b[i],i,nw*(a[i]-a[now])+ans1,nn-1);
			c[i]=true;
		}
}

int main(){
	cin>>n>>d;
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		c[i]=true;
		w+=y;
	}
	c[d]=false;
	w=w-b[d];
	hh(w,d,0,n-1);
	cout<<ans;
	return 0;
}
