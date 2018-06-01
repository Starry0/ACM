/************************************
将对称的字符串按从小到大的顺序输出，字符串
先以长度论大小，如果长度相同，再以ASCII码
值为排序标准。
***********************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool Comp(const string &s1,const string &s2){
    return s1.length()!=s2.length()?s1.length()<s2.length():s1<s2;
}
int main(){
    ifstream cin("in.txt");
    vector<string>v;
    string t,s;
    while(cin>>s){
        t=s;
        reverse(t.begin(),t.end());
        if(t==s){
          v.push_back(s);
        }
    }
    sort(v.begin(),v.end(),Comp);
    for(int i=0,len=v.size();i<len;i++){
      cout<<v[i]<<endl;
    }
    return 0;
}
