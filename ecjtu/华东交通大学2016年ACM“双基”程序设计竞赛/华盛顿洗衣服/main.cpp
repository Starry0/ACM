#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,q;
    while(cin>>n>>q){
        int i;
        char a[n+1][10000];
        for(i=0;i<n;i++)
            scanf("%s",&a[i]);
        for(int i=0;i<q;i++){
        int y,k=0;
        cin>>y;
        for(int j=0;j<n;j++)
            if(strstr(a[j],a[y-1]))k++;
        cout<<k<<endl;
       }
    }
    return 0;
}
