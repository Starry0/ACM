#include <bits/stdc++.h>
using namespace std;
int f[2020];
int main(){
    int n,a,b;
    while(~scanf("%d",&n)){
        memset(f,0,sizeof(f));
        for(int i = 0; i <= 2000; i++)
            f[i] = i;
        for(int i = 0; i < n; i++){
            scanf("%d%d",&a,&b);
            f[a] = b;
        }
        int ans = 0, ans1 = 0;
        for(int i = 1; f[i] != i; i = f[i], ans++);
        for(int i = 2; f[i] != i; i = f[i], ans1++);
        if(ans > ans1)
            cout<<"You are my elder"<<endl;
        else if(ans == ans1)
            cout<<"You are my brother"<<endl;
        else cout<<"You are my younger"<<endl;
    }
    return 0;
}
