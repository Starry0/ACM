#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 2e4+10;
int p[N], a[N], b[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> p[i];
        a[i] = i;
        b[i] = n-i+1;
    }
    for(int i = 1; i < n; i ++){
        int ans = a[p[i]] + b[p[i]];
        int ans1 = a[p[i+1]] + b[p[i+1]];
        //cout << ans << ' ' << ans1 << endl;
        int d = ans1 - ans;
        if(d > 0) continue;
        else{
            if(p[i+1] > p[i]){
                for(int j = p[i+1]; j <= n; j ++){
                    a[j] += 1 - d;
                }
            }
            else if(p[i+1] < p[i]){
                for(int j = 1; j <= p[i+1]; j ++){
                    b[j] += 1 - d;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        if(i == 1) printf("%d",a[i]);
        else printf(" %d",a[i]);
    }
    printf("\n");
    for(int i = 1; i <= n; i ++){
        if(i == 1) printf("%d",b[i]);
        else printf(" %d",b[i]);
    }
    printf("\n");
    return 0;
}
