#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char ss[maxn],s[maxn];
int main(){
  int i,j,len1,len2,len;
  while(cin>>s>>ss){
    len1 = strlen(s);
    len2 = strlen(ss);
    len = max(len1,len2);
    for(i=0;i<len1;i++){
      for(j=0;j<len2;j++){
        int a = s[i+j] - '0';
        int b = ss[j] - '0';
        if(a+b>3)
          break;
      }
      if(j==len2)
      break;
    }
    int x = i+len2;
    for(i=0;i<len2;i++){
      for(j=0;j<len1;j++){
        int a = ss[i+j] -'0';
        int b = s[j] - '0';
        if(a+b>3)
          break;
      }
      if(j==len1)
      break;
    }
    int y = i+len1;
    len = max(len,min(x,y));
    cout<<len<<endl;
    memset(s,0,sizeof(s));
    memset(ss,0,sizeof(ss));
  }
  return 0;
}
