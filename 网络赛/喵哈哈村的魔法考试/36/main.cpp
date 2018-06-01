#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    string s, ss;
    while(~scanf("%d",&n)){
        cin >> s >> ss;
        for(int i = 0; i < n; i++){
            if(s[i] == ss[i])
                s[i] = '0';
            else s[i] = '1';
        }
        cout << s << endl;
    }
    return 0;
}
