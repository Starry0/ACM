#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char str[N];
int n;
int main() {
    cin >> n >> str+1;
    for(int i = 1; i <= n; i ++) {
        if(n % i == 0) {
            for(int j = 1; j <= i/2; j ++) swap(str[j],str[i-j+1]);
        }
    }
    cout << str+1 << endl;
    return 0;
}
