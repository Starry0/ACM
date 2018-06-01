#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  int n,p=0;
  string ss;
  char s[10];
  cin>>n;
  while(scanf("%d%s",&n,s)!=EOF){
    ss=s;
    if(p==0&&ss=="North"){
      cout<<"NO"<<endl;
      return 0;
    }
    else if(p==20000&&ss=="South"){
      cout<<"NO"<<endl;
      return 0;
    }
    else if(ss=="North"){
      p=p-n;
      if(p<=-80000)
        p=-(p+80000);
      else if(p<=60000)
        p = 20000+(p+60000);
      else if(p<=40000)
        p = -(p+40000);
      else if(p<=20000)
        p = 20000+(p+20000);
      else if(p<=0)
        p = -p;
    }
    else if(ss=="South"){
      p = p + n;
      if(p>=100000)
      p=20000-(p-100000);
      else if(p>=80000)
        p =p-80000;
      else if(p>=60000)
        p =20000- (p-60000);
      else if(p>=40000)
        p =p-40000;
      else if(p>=20000)
        p = 20000-(p-20000);
    }
  }
  if(p==0)
  cout<<"YES"<<endl;
  return 0;
}
