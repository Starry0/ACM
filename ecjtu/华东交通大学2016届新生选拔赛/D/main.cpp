#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
string a[70];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        long long m=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            if(a[i]<10&&a[i]>1)
            m=m*10+a[i];
        }
        for(int i=0;i<n;i++)
            if(a[i]>10)
            m=m*100+a[i];
        for(int i=0;i<n;i++)
            if(a[i]==1)
            m=m*10+a[i];
        cout<<m<<endl;
    }
    return 0;
}
