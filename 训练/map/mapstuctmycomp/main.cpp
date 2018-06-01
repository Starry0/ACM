#include <iostream>
#include <string>
#include <map>
using namespace std;
struct Info{
    string name;
    float score;
    bool operator <(const Info &a)const{
        //按成绩从大到小
        return a.score<score;
    }
};
int main()
{
    map<Info,int> m;
    Info info;
    info.name="Nick";
    info.score=78.2;
    m[info]=11;
    info.name="dash";
    info.score=22.9;
    m[info]=22;
    info.name="gdyue";
    info.score=44.6;
    m[info]=44;
    map<Info,int>::iterator it;
    for(it=m.begin();it!=m.end();++it){
        cout<<(*it).second<<":";
        cout<<((*it).first).name<<' '<<((*it).first).score<<endl;
    }
    return 0;
}
