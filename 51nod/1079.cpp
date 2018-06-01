#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Nod{
    int p,m;
}nod[11];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i ++) cin>>nod[i].p>>nod[i].m;
    int ans = nod[0].m, cnt = 1;
    for(int i = 1; i < n; i ++){
        cnt = cnt*nod[i-1].p;
        while((ans%nod[i].p) != nod[i].m){
            ans+=cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
