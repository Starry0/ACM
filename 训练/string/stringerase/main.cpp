#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="abc123456";
    string::iterator it=s.begin();
    s.erase(it+3);
    cout<<s<<endl;
    s.erase(it,it+4);
    cout<<s<<endl;
    s="";
    cout<<s.length()<<endl;
    return 0;
}
