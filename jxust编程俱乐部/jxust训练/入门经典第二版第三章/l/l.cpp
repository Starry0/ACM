#include <bits/stdc++.h>
using namespace std;
char DNA[52][1010],a[4]={'A','C','G','T'};
struct DATE{
  char ch;
  int num;
}date[4],maxn;
int main(){
  int t,n,m;
  cin>>t;
  while(t--){
    cin>>m>>n;
    int minx =0;
    for(int i=0;i<4;i++)
      date[i].ch = a[i];
    getchar();
    for(int i=0;i<m;++i)
      gets(DNA[i]);
    for(int j=0;j<n;j++){
      for(int i=0;i<4;i++)
        date[i].num = 0;
      for(int i=0;i<m;i++){
        if(DNA[i][j]=='A')date[0].num++;
        else if(DNA[i][j]=='C')date[1].num++;
        else if(DNA[i][j]=='G')date[2].num++;
        else if(DNA[i][j]=='T')date[3].num++;
      }
      maxn = date[0];
      for(int i=1;i<4;i++)
        if(date[i].num>maxn.num)
          maxn = date[i];
      printf("%c",maxn.ch);
      minx += m -maxn.num;
    }
    printf("\n%d\n",minx);
  }
  return 0;
}
