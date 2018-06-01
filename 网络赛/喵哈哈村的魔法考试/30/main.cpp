#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int k;
    while(cin >> k){
        string s;
        cin >> s;
        int num = 1;
        for(int i = 1,l = s.length(); i < l; i++){
            if(s[i] == s[i-1]){
                num++;
            }
            else{
                num = 1;
            }
            if(num == k){
                cout << "Lose" <<endl;
                goto tt;
            }
        }
        cout << "Win" <<endl;
        tt :;
    }
    return 0;
}
