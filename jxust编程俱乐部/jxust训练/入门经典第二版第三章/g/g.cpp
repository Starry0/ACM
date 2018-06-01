#include <bits/stdc++.h>
using namespace std;
map<char,int>m;
int main(){
  string s;
  int n;
  cin>>n;
  while(n--){
    cin>>s;
    char c;
    float sn = 0;
    int a=0;
    for(int i=0;i<s.length();i++){
      if(!isalpha(s[i])){
        a = a*10 +s[i]-'0';
      }
      else {
        //cout<<a<<endl;
        if(a!=0)
          m[c]+=(a-1);
        m[s[i]]++;
        c = s[i];
        a=0;
      }
    }
    if(a!=0)
      m[c]+=(a-1);
  //  cout<<m['C']<<' '<<m['H']<<' '<<m['N']<<' '<<m['O']<<endl;
    sn = m['C']*12.01+m['H']*1.008+m['O']*16.00+m['N']*14.01;
    printf("%.3f\n",sn);
    m.clear();
  }
  return 0;
}
