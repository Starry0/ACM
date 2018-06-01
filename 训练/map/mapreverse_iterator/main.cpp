#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,int> m;
    m["Nind"]=89;
    m["Jack"]=66;
    m["Anda"]=100;
    map<string,int>::reverse_iterator rit;
    for(rit=m.rbegin();rit!=m.rend();++rit)
        cout<<(*rit).first<<' '<<(*rit).second<<endl;


    return 0;
}
