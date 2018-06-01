#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(33);
    s.insert(23);
    s.insert(232);
    s.insert(888);
    s.insert(157);
    s.insert(33);
    //删除键值为33的那个元素
    s.erase(33);
    set<int>::reverse_iterator rit;
    for(rit=s.rbegin();rit!=s.rend();rit++)
        cout<<*rit<<' ';
    cout<<endl;
    s.clear();
    cout<<s.size()<<endl;
    return 0;
}
