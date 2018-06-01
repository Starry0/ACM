#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Nod{
    int p, w;
}nod[1010];
bool cmp(Nod a, Nod b){
    return a.p < b.p;
}
int main(){
    int n, m;
    while(~scanf("%d%d",&n,&m)){
        for(int i = 0; i < m; i ++){
            cin >> nod[i].p >> nod[i].w;
        }
        double sum = 0;
        sort(nod,nod+m,cmp);
        for(int i = 0; i < m; i ++){
            //  cout << n << ' ' << nod[i].p << endl;
            //  cout << sum << endl;
            if(nod[i].p*nod[i].w <= n){
                sum += nod[i].w;
                n = n - nod[i].p*nod[i].w;
            }else{
                sum += n*1.0/nod[i].p*1.0;
                break;
            }
        }
        printf("%.4lf\n",sum);
    }
    return 0;
}
