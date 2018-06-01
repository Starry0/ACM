#include <iostream>
#include <cmath>
using namespace std;
int prime[10010],pri[10010];
int main()
{
    prime[2] = 1;
    pri[0] = 2;
    int k = 1;
    for(int i = 3; i < 10000; i += 2){
        int flag = 1;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            prime[i] = 1;
            pri[k++] = i;
        }
    }
    int n;
    while(cin >> n){
        int ans = 0;
        for(int i = 0; i < k; i++){
            for(int j = i; j < k; j++){
                if(pri[i] + pri[j] >= n)
                    break;
                int t = n - pri[i] - pri[j];
                if(prime[t] && t >= pri[j]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
