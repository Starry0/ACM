#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[10] = {9,13,15,7,45,32,56,89,60,36};
    cin>>n;
    for(int i=0;i<10;i++){
        if(n==a[i]){
            cout<<"index="<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
