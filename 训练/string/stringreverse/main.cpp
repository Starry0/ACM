#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    s="123456789";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    //������Ϊ987654321
    return 0;
}
