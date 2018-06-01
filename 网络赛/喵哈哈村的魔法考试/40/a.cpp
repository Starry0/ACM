#include <bits/stdc++.h>
using namespace std;
struct Nod{
    int a, b;
}nod[110];
bool cmp(Nod a, Nod b){
    if(a.a != b.a) return a.b > b.b;
    else return a.a < b.a;
}
int main(){
    int n,a;
    while(cin>>n>>a){
        for(int i = 0; i < n; i ++) cin>>nod[i].a>>nod[i].b;
        sort(nod,nod+n,cmp);
        int i;
        for(i = 0; i < n; i ++){
            if(nod[i].a <= a){
                cout << nod[i].b << endl;
                break;
            }
        }
        if(i == n) cout << 0 << endl;
    }
    return 0;
}
