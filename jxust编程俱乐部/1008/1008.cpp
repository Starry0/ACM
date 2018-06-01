#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

 int dist[110][110];
struct DATE{
  int left;
  int right;
  int len;
}date[1010];

int main(){
  int n,m,k;
  while(scanf("%d%d%d",&n,&m,&k)!=EOF){
    if(n||m||k)
      break;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i==j) dist[i][j]=0;
        else dist[i][j]=inf;
      }
    }
    for(int i=0;i<m;i++){
      cin>>date[i].left>>date[i].right>>date[i].len;
    }
    for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          a[i][j]=min(a[i][j],a[k][i]+a[k][j]);
        }
      }
    }

  }

}
