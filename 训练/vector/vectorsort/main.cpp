#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(9-i);
    for(int i=0;i<10;i++)
        cout<<v[i]<<' ';
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<10;i++)
        cout<<v[i]<<' ';
    cout<<endl;
    return 0;
}
