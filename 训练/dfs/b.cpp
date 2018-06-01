#include <iostream>
using namespace std;
char a[10];
int main(){
    int res = 0, ans = 0;
    for(int i = 0; i < 8; i ++){
        cin >> a;
        int k = 0;
        for(int i = 0; i < 8; i ++){
            if(a[i] == 'B') k++;
        }
        //cout << k << endl;
        if(k == 8) ans ++;
        else res = k;
    }
    if(ans == 8) cout << ans << endl;
    else cout << ans + res << endl;
    return 0;
}
