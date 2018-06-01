#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    //getchar();
    t++;
    for(int j=0;j<t;j++){
            char c,a[10000],d;
            int m=0;
        while((c=getchar())!='\n'){
            if(c>='0'&&c<='9'){
                for(int i=0;i<(int)(c)-48;i++)
                    a[m++]=d;
            }
            else a[m++]=c;
            if(c>='0'&&c<='9'){}
                else d=c;
        }
        if(j==0)continue;
        else puts(a);
        memset(a,0,10000*sizeof(char));
    }
    return 0;
}
