#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="cat dog cat";
    cout<<s.find('c')<<endl;
    cout<<s.find("c")<<endl;
    cout<<s.find("cat")<<endl;
    cout<<s.find("dog")<<endl;
    //�Ҳ������4294967295
    cout<<s.find("dogc")<<endl;
    return 0;
}
