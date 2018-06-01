#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int h,a,b;
    while(scanf("%d%d%d",&h,&a,&b)!=EOF){
        int c=0,t=0;
        c+=a;
        t++;
        while(c<h){
            c-=b;
            t++;
            c+=a;
            t++;
        }
        cout<<t<<endl;
    }
    return 0;
}
