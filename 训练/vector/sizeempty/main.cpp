#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v(10);
    for(int i=0;i<10;i++)
        v[i]=i;
    cout<<v.size()<<endl;
    cout<<v.empty()<<endl;
    v.clear();
    cout<<v.empty()<<endl;
    return 0;
}
