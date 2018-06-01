#include <bits/stdc++.h>
using namespace std;
char a[11][11];
int b[11][11];
int main(){
  int r,c,k=0;
  while(cin>>r){
    if(r==0)
      break;
    int ans = 1;
    cin>>c;
    for(int i=1;i<=r;i++)
      for(int j=1;j<=c;j++){
        cin>>a[i][j];
        if(a[i][j]!='*'&&(i-1<1||j-1<1||a[i-1][j]=='*'||a[i][j-1]=='*'))
          b[i][j] = ans++;
      }
    if(k)
      printf("\n");
    printf("puzzle #%d:\nAcross\n",++k);
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        if(b[i][j]){
          printf("%3d.",b[i][j]);
          while(1){
            printf("%c",a[i][j]);
            j++;
            if(a[i][j]=='*'||j>c)
              break;
          }
          printf("\n");
        }
      }
    }
    printf("Down\n");
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        if(b[i][j]){
          printf("%3d.",b[i][j]);
          int m = i;
          while(1){
            //cout<<m<<endl;
            printf("%c",a[m][j]);
            b[m][j]=0;
            m++;
            if(a[m][j]=='*'||m>r)
              break;
          }
          printf("\n");
        }
      }
    }
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
  }
  return 0;
}
