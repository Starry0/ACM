#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="abc123456";
    s.replace(3,3,"good");
    cout<<s<<endl;
    return 0;
}
//������Ϊ��abcgood456
