#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int a[1010];
int main(){
    int n;
    while( ~scanf("%d" ,&n) && n){
        for( int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a, a + n);
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)
                        continue;
                    for(int l = 0; l < n; l++){
                        if(l == i || l == j || l == k)
                            continue;
                        if(a[i] == (a[j] + a[l] + a[k]) ){
                            cout << a[i] << endl;
                            goto tt;
                        }
                    }
                }
            }
        }
        cout << "no solution" <<endl;
        tt :;
    }
    return 0;
}
