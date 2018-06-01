#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 7510
using namespace std;

ll a[maxn];
int main(){
  int k,s;
  ll ans=0;
  scanf("%d%d",&k,&s);
  for(int x=0;x<=k;x++){
    for(int y=0;y<=k;y++){
      if(s-x-y<=k&&s-x-y>=0)
        ans++;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
