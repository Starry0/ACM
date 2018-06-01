#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    int n;
    cin>>n;
    getchar();
    while(n--){
        getline(cin,s);
        cout<<s<<endl<<endl;;
    }
    while(cin>>s)
        cout<<s<<endl<<endl;;
    return 0;
}
