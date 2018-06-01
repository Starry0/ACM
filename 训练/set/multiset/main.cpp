#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    multiset<string> s;
    s.insert("dewew");
    s.insert("dddda");
    s.insert("11111");
    s.insert("11111");
    s.insert("22222");
    multiset<string>::iterator it;
    for(it=s.begin();it!=s.end();++it)
        cout<<*it<<endl;
    cout<<endl;
    s.erase("11111");
    for(it=s.begin();it!=s.end();++it)
        cout<<*it<<endl;
    it=s.find("1111");
    if(it==s.end())
        cout<<"not find it!"<<endl;
    return 0;
}
