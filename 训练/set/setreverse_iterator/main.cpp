#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(8);
    s.insert(22);
    s.insert(82);
    s.insert(299);
    s.insert(8);
    set<int>::reverse_iterator rit;
    for(rit=s.rbegin();rit!=s.rend();++rit)
        cout<<*rit<<' ';
    cout<<endl;
    return 0;
}
