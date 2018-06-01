#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;
map<string,int> m;
int main()
{
    int n;
    string s;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            cin>>s;
            m[s]++;
        }
        map<string,int>::iterator it=m.begin();
        map<string,int>::iterator it1=m.begin();
        for(++it;it!=m.end();++it){
            if((*it).second>(*it1).second){
                it1=it;
            }
        }
        cout<<(*it1).first<<endl;
        m.clear();
    }
    return 0;
}
