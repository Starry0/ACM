#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(8);
    s.insert(11);
    s.insert(6);
    s.insert(90);
    s.insert(8);
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();++it)
        cout<<*it<<' ';
    return 0;
}
