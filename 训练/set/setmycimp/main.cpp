#include <iostream>
#include <set>
using namespace std;

struct mycomp{
    bool operator () (const int &a,const int &b)
    {
        return a>b;
    }
};
int main()
{
    set<int,mycomp> s;
    s.insert(28);
    s.insert(278);
    s.insert(89);
    s.insert(89);
    s.insert(88);
    set<int,mycomp>::iterator it;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
