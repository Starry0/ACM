#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
char str[N];
typedef pair<int,int> P;
map<char,P> mp;
void init() {
    mp['@'] = mp['!'] = mp[':'] = P(1,1);
    mp['A'] = mp['B'] = mp['C'] = P(1,2);
    mp['D'] = mp['E'] = mp['F'] = P(1,3);
    mp['G'] = mp['H'] = mp['I'] = P(2,1);
    mp['J'] = mp['K'] = mp['L'] = P(2,2);
    mp['M'] = mp['N'] = mp['O'] = P(2,3);
    mp['P'] = mp['Q'] = mp['R'] = mp['S'] = P(3,1);
    mp['T'] = mp['U'] = mp['V'] = P(3,2);
    mp['W'] = mp['X'] = mp['Y'] = mp['Z'] = P(3,3);
}
int main() {
    int t;
    init();
    cin >> t;
    while(t--) {
        cin >> str;
        int ans = 0;
        int x = 1, y = 1;
        for(int i = 0; str[i]; i ++) {
            int nx = mp[str[i]].first, ny = mp[str[i]].second;
            ans += abs(nx-x)+abs(ny-y);
            x = nx, y = ny;
        }
        cout << ans << endl;
    }
    return 0;
}
