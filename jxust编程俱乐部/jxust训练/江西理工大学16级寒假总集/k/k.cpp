#include <bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int di[1010][1010];

struct DATE{
  int left;
  int right;
  int len;
}date[1010];

int main(){
  int n,m,a,b,c;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)
        di[i][j]=0;
      else
        di[i][j]=inf;
    }
  }
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&date[i].left,&date[i].right,&date[i].len);
    di[date[i].left][date[i].right]=date[i].len;
    di[date[i].right][date[i].left]=date[i].len;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        di[j][k]=min(di[j][k],di[i][j]+di[i][k]);
      }
    }
  }
  int ans=m;
  for(int i=0;i<m;i++){
    int kk=0;
    a=date[i].left;b=date[i].right;c=date[i].len;
    for(int j=1;j<=n;j++){
      if(di[j][a]+c==di[j][b])
        kk=1;
    }
    if(kk)
      ans--;
  }
  cout<<ans<<endl;
  return 0;
}
