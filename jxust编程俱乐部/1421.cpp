#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
using namespace std;
 
int main()
{
    char a[]={" _     _  _     _  _  _  _  _ "};
    char b[]={"| |  | _| _||_||_ |_   ||_||_|"};
    char c[]={"|_|  ||_  _|  | _||_|  ||_| _|"};
    char d[11];
    cin>>d;
    for(int i=0;i<strlen(d);i++){
        printf("%c%c%c",a[3*(d[i]-'0')],a[3*(d[i]-'0')+1],a[3*(d[i]-'0')+2]);
    }
    printf("\n");
    for(int i=0;i<strlen(d);i++){
        printf("%c%c%c",b[3*(d[i]-'0')],b[3*(d[i]-'0')+1],b[3*(d[i]-'0')+2]);
    }
    printf("\n");
    for(int i=0;i<strlen(d);i++){
        printf("%c%c%c",c[3*(d[i]-'0')],c[3*(d[i]-'0')+1],c[3*(d[i]-'0')+2]);
    }
    printf("\n");
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
string s,s1,s2,s3;
int main(){
  cin>>s;
  int len=s.length();
  for(int i=0;i<len;i++){
    if(s[i]=='0')
      s1+=" _ ",s2+="| |",s3+="|_|";
    else if(s[i]=='1')
      s1+="   ",s2+="  |",s3+="  |";
    else if(s[i]=='2')
      s1+=" _ ",s2+=" _|",s3+="|_ ";
    else if(s[i]=='3')
      s1+=" _ ",s2+=" _|",s3+=" _|";
    else if(s[i]=='4')
      s1+="   ",s2+="|_|",s3+="  |";
    else if(s[i]=='5')
      s1+=" _ ",s2+="|_ ",s3+=" _|";
    else if(s[i]=='6')
      s1+=" _ ",s2+="|_ ",s3+="|_|";
    else if(s[i]=='7')
      s1+=" _ ",s2+="  |",s3+="  |";
    else if(s[i]=='8')
      s1+=" _ ",s2+="|_|",s3+="|_|";
    else
      s1+=" _ ",s2+="|_|",s3+=" _|";
  }
  cout<<s1<<endl;
  cout<<s2<<endl;
  cout<<s3<<endl;
  return 0;
}*/