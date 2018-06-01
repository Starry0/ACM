#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 55;
int a[maxn], b[maxn], c[maxn], d[maxn];
int main(){
    int n,m;
    while(cin >> n >> m){
        for(int i = 1; i <= n; i ++){
            cin >> a[i] >> b[i];
        }
        for(int i = 1; i <= m; i ++){
            cin >> c[i] >> d[i];
        }
        for(int i = 1; i <= n; i++){
            int ans = 1;
            int pos = abs(a[i] - c[1]) + abs(b[i]-d[1]);
            for(int j = 2; j <= m; j ++){
                int pos1 = abs(a[i] - c[j]) + abs(b[i]-d[j]);
                //cout << pos1 << endl;
                if(pos1 < pos){
                    //cout << pos1 << ' ' << pos << endl;
                    ans = j;
                    pos = pos1;
                //    cout << pos1 << ' ' << pos << endl;
                //    cout << j << endl;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
