#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    t++;
    char c;
    for(int i=1;i<=t;i++){
            char a[10000];
            int m=0;
        while((c=getchar())!='\n'){
            if(c=='#')
                {m--;
                continue;}
            else if(c=='@')
                {m=0;
                memset(a,0,10000*sizeof(char));
                continue;}
            a[m++]=c;
        }
        if(i==1)continue;
        else {for(int i=0;i<m;i++)
            cout<<a[i];
            cout<<endl;
        }
    }
    return 0;
}
