#include <bits/stdc++.h>
using namespace std;
char a[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* ms[] = {"","","",""};
int main(){
  map<char,char> m;
  for(int i=0;i<35;i++){
    if(i<26)
      m['A'+i]=a[i];
    else m['1'+i-26]=a[i];
  }
  string s,ss;
  char sss[30];
  int n=0;
  while(scanf("%s",sss)!=EOF){
    s=sss;
    ss=s;
    int flag=1,flag1=1;
    reverse(ss.begin(),ss.end());
    if(ss==s)
      flag=1;
    else flag=0;
    for(int i=0;i<(s.length()+1)/2;i++){
      //cout<<m[s[i]]<<' '<<s[s.length()-1-i]<<endl;
      if(m[s[i]]!=s[s.length()-1-i])
        flag1=0;
    }
    //cout<<flag<<' '<<flag1<<endl;
    /*if(n!=0)
      printf("\n");*/
    if(flag&&flag1)
      printf("%s -- is a mirrored palindrome.\n\n",sss);
    else if(flag==1&&flag1==0)
      printf("%s -- is a regular palindrome.\n\n",sss);
    else if(flag==0&&flag1==0)
      printf("%s -- is not a palindrome.\n\n",sss);
    else if(flag==0&&flag1==1)
      printf("%s -- is a mirrored string.\n\n",sss);
    ss=s="";n++;
  }
}
