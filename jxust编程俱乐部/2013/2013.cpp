#include <bits/stdc++.h>
using namespace std;
int f(int x){
    int maxn=2,i=2;
    while(x>1){
        if(x%i==0){
            maxn=i;
            while(x%i==0)
                x/=i;
        }
        i++;
    }
    return maxn;
}
int main(){
    int n,a;
    cin>>n>>a;
    n--;
    int maxn = f(a),manxx=a;
    while(n--){
        cin>>a;
        int maxn1=f(a);
        if(maxn1>maxn){
            maxn=maxn1;
            manxx=a;
        }
    }
    cout<<manxx<<endl;
    return 0;
}
