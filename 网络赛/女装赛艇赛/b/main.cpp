#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        s.insert(m);
    }
    for(int i=1;i<=n;i++){
        if(s.count(i))
            continue;
        else cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}
