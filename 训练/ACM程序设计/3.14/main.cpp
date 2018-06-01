/************************************
将01串首先按长度排序，长度相同时，按1的个
数进行排序，1的个数相同时再按ASCII码值排序。
***********************************/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
struct Comp{
    bool operator()(const string &s1,const string &s2){
        if(s1.length()!=s2.length())return s1.length()<s2.length();
        int c1=count(s1.begin(),s1.end(),'1');
        int c2=count(s2.begin(),s2.end(),'1');
        return (c1!=c2?c1<c2:s1<s2);
    }
};
int main(){
    multiset<string,Comp>ms;
    ifstream cin("in.txt");
    string s;
    while(cin>>s){
        ms.insert(s);
    }
    for(multiset<string,Comp>::iterator it=ms.begin();it!=ms.end();++it){
        cout<<*it<<endl;
    }
    return 0;
}
