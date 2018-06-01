#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n){
            int z=0,o=0,f=0;
            float m;
        for(int i=1;i<=n;i++){
            cin>>m;
            if(m>0)z++;
            else if(m==0)o++;
            else f++;
        }
        cout<<f<<' '<<o<<' '<<z<<endl;
    }
    return 0;
}
