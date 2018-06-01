#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int n,m;
int fa[maxn];
int fi(int x){
    return fa[x]==x?x:fa[x]=fi(fa[x]);
}
void uni(int x,int y){
    x = fi(x),y = fi(y);
    fa[x]=y;
}
void solve(){
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            uni(b,c);
        }else{
            if(fi(b)==fi(c)){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
}
int main(){
    while(cin>>n>>m)solve();
    return 0;
}
