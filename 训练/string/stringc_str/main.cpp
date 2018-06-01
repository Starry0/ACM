#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    char ss[100];
    string s;
    scanf("%s",&ss);
    s=ss;
    printf(s.c_str());
    cout<<endl;
    printf("%s\n",ss);
    cout<<s<<endl;
    cout<<ss<<endl;
    return 0;
}
