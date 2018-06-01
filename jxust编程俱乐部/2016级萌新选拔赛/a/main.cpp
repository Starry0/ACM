#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int>m;
int main()
{
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        m[a]++;
    }
    if((n-m.size())%2==0)
        cout<<m.size()<<endl;
    else cout<<m.size()-1<<endl;
    return 0;
}
