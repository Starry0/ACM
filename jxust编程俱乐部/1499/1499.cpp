#include <bits/stdc++.h>
using namespace std;
int a[110][110];
char b[110][110];
int main(){
  int n,m,k=1;
  while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>b[i][j];
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(b[i][j]=='*'){
          a[i-1][j-1]++;
          a[i-1][j]++;
          a[i-1][j+1]++;
          a[i][j-1]++;
          a[i][j+1]++;
          a[i+1][j-1]++;
          a[i+1][j]++;
          a[i+1][j+1]++;
        }
      }
    }
    if(k!=1)
      cout<<endl;
    printf("Field #%d:\n",k++);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(b[i][j]=='*')
          cout<<b[i][j];
        else cout<<a[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}
