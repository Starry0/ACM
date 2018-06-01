#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x = 1;
    while(x <= n) x<<=1;
    printf("%d\n",x>>1);
    return 0;
}
