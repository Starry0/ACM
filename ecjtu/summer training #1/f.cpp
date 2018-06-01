#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m[1010],a,b,k=1;

int find(int x){
    for(int i = 1; i <= 1001; i ++){
        if(x < m[i]){
            return i-1;
        }
    }
}
int main(){
    for(int i = 1; i <= 1001; i ++){
        m[k++] = i*i;
    }
    while(scanf("%d %d",&a,&b)!= EOF){
        if(a == 0 && b == 0) break;
        int x = find(a),y = find(b);
        int cnt = (int)sqrt(a);
        if(cnt*cnt == a) printf("%d\n",y-x+1);
        else printf("%d\n",y-x);
    }
    return 0;
}
