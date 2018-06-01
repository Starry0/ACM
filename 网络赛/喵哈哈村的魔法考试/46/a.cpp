#include <bits/stdc++.h>
using namespace std;
struct Nod {
    int num;
    int coc;
}nod[55];
char c;
bool cmp(Nod x, Nod y){
    if(x.coc != y.coc) return x.coc > y.coc;
    else return x.num < y.num;
}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < 55; i ++)nod[i].num = i, nod[i].coc = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> c;
                if(i == j)break;
                if(c == 'W'){
                    nod[i].coc+=3;
                }else if(c == 'D'){
                    nod[i].coc+=1;
                    nod[j].coc+=1;
                }
                cout << nod[1].coc<<endl;
            }
        }

        sort(nod+1,nod+1+n,cmp);
        // for(int i = 1; i <= n; i ++) cout << nod[i].num << ' ' <<nod[i].coc<<endl;
        for(int i = 1; i <= n; i ++){
            if(i == 1) cout << nod[i].num;
            else cout << ' ' << nod[i].num;
        }
        cout << endl;
    }
    return 0;
}
