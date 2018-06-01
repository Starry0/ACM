#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 1e6+10;
ll a[maxn];
int main(){
    int n;
    while(~scanf("%d",&n)){
        if((n+2)%4) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
