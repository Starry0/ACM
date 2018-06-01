#include <iostream>
#include<bits/stdc++.h>

using namespace std;
struct node{int x,y;}N[1005];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int n,m,s;
    cin>>n>>m;
    s=n+m;
    for(int i=0;i<s;i++)cin>>N[i].x>>N[i].y;
    sort(N,N+s,cmp);
    for(int i=0;i<s;i++)cout<<N[i].x<<' '<<N[i].y<<endl;
    return 0;
}
