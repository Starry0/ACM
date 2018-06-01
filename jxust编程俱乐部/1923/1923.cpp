#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[90];
int main(){
  while(gets(a)!=NULL){
    if(strcmp(a,"End of file")==0)
      break;
    for(int i=0;i<strlen(a);i++){
      if(a[i]==' ')
        continue;
      else cout<<a[i];
    }
    cout<<endl;
    memset(a,0,sizeof(a));
  }
  return 0;
}
