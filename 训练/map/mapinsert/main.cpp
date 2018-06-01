#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,int> m;
    m["Mike"]=88;
    m["Jack"]=89;
    m["Nick"]=99;
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();++it)
        cout<<(*it).first<<' '<<(*it).second<<endl;
    cout<<endl;
    m.erase("Mike");
    for(it=m.begin();it!=m.end();++it)
        cout<<(*it).first<<' '<<(*it).second<<endl;

    return 0;
}
