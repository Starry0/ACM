#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int j=0,o=0;
        if(n>m){n=n+m;m=n-m;n=n-m;}
        for(int i=n;i<=m;i++){
            if((i+1)%2==0)j=j+i*i*i;
            else if(i%2==0)o=o+i*i;
        }
        cout<<o<<' '<<j<<endl;
    }
    return 0;
}
