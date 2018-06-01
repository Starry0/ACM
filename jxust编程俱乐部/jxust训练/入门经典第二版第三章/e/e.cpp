#include <bits/stdc++.h>
const int maxn = 1e5+10;
int a[maxn];
using namespace std;
int main(){
  memset(a,0,sizeof(a));
  for(int i = 1;i < maxn; i++){
    int y = i,x = i;
    while(x>0){
      y= y+ x%10;
      x/=10;
    }
    if(a[y]==0)
    a[y]=i;
  }
  int t,n;
  cin>>t;
  while(t--){
    scanf("%d",&n);
    printf("%d\n",a[n]);
  }
  return 0;
}
