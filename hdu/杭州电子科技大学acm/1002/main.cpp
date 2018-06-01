#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<char,int> m;
vector<int> v;
void f(string s,string ss){
    reverse(s.begin(),s.end());reverse(ss.begin(),ss.end());
    if(s.length()>ss.length())
        swap(s,ss);
    int a,b,sum,flags=0;
    for(int i=0;i<ss.length();++i){
        if(i>=s.length())
            a=0;
        else a=m[s[i]];
        b=m[ss[i]];
        sum=a+b+flags;
        if(sum>=10){
            sum-=10;
            flags=1;
        }
        else flags=0;
        v.push_back(sum);
    }
    if(flags)
        v.push_back(1);
    reverse(v.begin(),v.end());
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it;
    cout<<endl;
}
int main()
{
    for(int i=0;i<10;i++){
        m['0'+i]=i;
    }
    int t,i=1;
    string ss,s;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>s>>ss;
        printf("Case %d:\n",i++);
        cout<<s<<" + "<<ss<<" = ";
        f(s,ss);
        if(j!=t-1)
        cout<<endl;
        v.clear();
    }
    return 0;
}
