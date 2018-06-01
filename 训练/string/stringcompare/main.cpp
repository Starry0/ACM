#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="cat dog cat";
    //s比“cat”字符串大，返回整数
    cout<<s.compare("cat")<<endl;
    //s与“cat dog cat ”相等，返回0；
    cout<<s.compare("cat dog cat")<<endl;
    //s比“dog”小，返回-1
    cout<<s.compare("dog")<<endl;
    return 0;
}
