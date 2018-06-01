#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int  n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int i = 0;
    while(i < n){
        while(a[i] == a[i+1])i++;
        i++;
        if(i >= n ) ans ++;
        if(a[i] >= a[i-1] && i < n){
            ans++;
            while(a[i] >= a[i-1] && i < n) i++;
        }
        else if(a[i] <= a[i-1] && i < n){
            ans ++;
            while(a[i] <= a[i-1] && i < n)i++;
        }
    }
    cout << ans << endl;
    return 0;
}
