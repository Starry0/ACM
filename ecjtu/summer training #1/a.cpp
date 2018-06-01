#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int a1, a2;
    cin >> a1 >> a2;
    int ans = 0;
    while(a1 > 0 && a2 > 0){
        if(a1 > a2)swap(a1,a2);
         if(a1 < 2 && a2 < 2) break;
        a1 += 1;
        a2 -= 2;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
