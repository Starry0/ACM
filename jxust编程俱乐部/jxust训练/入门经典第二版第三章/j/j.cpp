#include <bits/stdc++.h>
using namespace std;
char a[6][6];
int main(){
  int n=0;
  string c;
  string s;
  while(gets(a[0])){
    if(a[0][0]=='Z')
      break;
    for(int i=1;i<5;i++)
      gets(a[i]);
    int x,y;
    for(int i=0;i<5;i++)
      for(int j=0;j<5;j++){
        if(a[i][j]==' '){
          x=j;y=i;
          break;
        }
      }
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        printf(" %c",a[i][j]);
      }
      printf("\n");
    }
    int flag = 1;
    cin>>c;
    for(int i=0;c[i]!='0';i++){
      if(c[i]=='A'){
        swap(a[y][x],a[y-1][x]);
        y--;
      }
      if(c[i]=='D'){
        swap(a[y][x],a[y+1][x]);
        y++;
      }
      if(c[i]=='L'){
        swap(a[y][x],a[y][x-1]);
        x--;
      }
      if(c[i]=='R'){
        swap(a[y][x],a[y][x+1]);
        x++;
      }
      if(x>4||x<0||y>4||y<0){
        flag=0;
        break;
      }
    }
    if(n) printf("\n");
    printf("Puzzle #%d:\n",++n);
    if(flag){
      for(int i=0;i<5;i++){
        printf("%c",a[i][0]);
        for(int j=1;j<5;j++){
          printf(" %c",a[i][j]);
        }
        cout<<endl;
      }
    }
    else printf("This puzzle has no final configuration.\n");
    memset(a,0,sizeof(a));
  }
  return 0;
}
