#include <iostream>
#include <set>
#include <string>
using namespace std;
struct Info{
    string name;
    float score;
    //���ء�<�����������Զ����������
    bool operator < (const Info &a)const{
        //��score�Ӵ�С�������Ҫ��С��������ʹ�á�>���ż���
        return a.score<score;
    }
};
int main()
{
    set<Info> s;
    Info info;
    info.name="Jack";
    info.score=80.4;
    s.insert(info);
    info.name="Mike";
    info.score=99.2;
    s.insert(info);
    info.name="Nacy";
    info.score=77.2;
    s.insert(info);
    set<Info>::iterator it;
    for(it=s.begin();it!=s.end();++it)
        cout<<(*it).name<<' '<<(*it).score<<endl;
    return 0;
}
