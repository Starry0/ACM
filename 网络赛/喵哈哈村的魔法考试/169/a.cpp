#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[30] = {0,1,2,3,3,4,4,5,5,6,6,6,7,7,7,7,7,
                7,9,10,11,12,12,12,13,14,15,16};
    char l ,r;
    int ll, rr;
    while(cin>>l>>r){
        if(l >= 'A' && l <= 'R'){
            ll = l - 'A' + 10;
        }else if(l >= '1' && l <= '9'){
            ll = l - '0';
        }
        if(r >= 'A' && r <= 'R'){
            rr = r - 'A' + 10;
        }else if(r >= '1' && r <= '9'){
            rr = r - '0';
        }
        cout << a[rr] - a[ll-1] << endl;
    }
    return 0;
}
