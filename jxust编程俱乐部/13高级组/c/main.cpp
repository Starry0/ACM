#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        char str1[10000],str2[10000];
        cin>>str1>>str2;
        if(strstr(str2,str1))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
