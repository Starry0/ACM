#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    reverse(a.begin(),a.end());
    cout<<a<<endl;
    return 0;
}
