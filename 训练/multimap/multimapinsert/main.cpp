#pragma warning(disable:4786)
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    multimap<string,double> m;
    m.insert(pair<string,double>("Jack",300.3));
    m.insert(pair<string,double>("Kity",200));
    m.insert(make_pair("Memi",500));
    m.insert(map<string,double>::value_type("Jack",300.6));
    multimap<string,double>::iterator it;
    for(it=m.begin();it!=m.end();++it)
        cout<<(*it).first<<' '<<(*it).second<<endl;

    return 0;
}
