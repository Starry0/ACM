#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char c,a[1000000];
    int b=0,m=0;
    while((c=getchar())!='\n'){
        if(c>='0'&&c<='9'){
            b=(int)c-48+b*10;
        }
        else {
            for(int i=1;i<=b;i++)
                a[m++]=c;
                b=0;
        }
    }
    puts(a);
    return 0;
}
