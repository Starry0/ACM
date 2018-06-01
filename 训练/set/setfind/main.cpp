#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int>s;
    s.insert(267);
    s.insert(27);
    s.insert(88);
    s.insert(99);
    s.insert(999);
    s.insert(99);
    set<int>::iterator it;
    it=s.find(88);
    if(it!=s.end())
        cout<<*it<<endl;
    else
        cout<<"not find it!"<<endl;
    it=s.find(100);
    if(it!=s.end())
        cout<<*it<<endl;
    else cout<<"not find it!"<<endl;
    return 0;
}
