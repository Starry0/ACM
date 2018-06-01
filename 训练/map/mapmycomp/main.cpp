#include <iostream>
#include <map>
#include <string>
using namespace std;

struct mycomp{
    bool operator ()(const int&a,const int &b)
    {
        return a>b;
    }
};

int main()
{
    map<int,string,mycomp> m;
    m[22]="sahdai";
    m[77]="dhgdwd";
    m[33]="addsd";
    map<int,string,mycomp>::iterator it;
    for(it=m.begin();it!=m.end();++it)
        cout<<(*it).first<<' '<<(*it).second<<endl;
    return 0;
}
