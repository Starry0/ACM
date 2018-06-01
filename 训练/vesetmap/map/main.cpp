#include <cstdio>
#include <stack>
#include <list>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define BitCount(x) __builtin_popcount(x)
#define BitCountll(x) __builtin_popcountll(x)
#define LeftPos(x) 32 - __builtin_clz(x) - 1
#define LeftPosll(x) 64 - __builtin_clzll(x) - 1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1000 + 10;
const int MOD = 1000007;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
typedef pair<int, int> pii;
typedef vector<int>::iterator viti;
typedef vector<pii>::iterator vitii;
vector<string> ans;
set<string> st;
map<string, string> mp;
int main()
{
   // ROP;
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string from, to;
        cin >> from >> to;
        st.insert(to);
        if (!st.count(from)) ans.PB(from);
        mp[from] = to;
    }
    cout << SZ(ans) << endl;
    for (i = 0; i < SZ(ans); i++)
    {
        string tmp = ans[i];
        while (mp.count(mp[tmp])) tmp = mp[tmp];
        cout << ans[i] << " " << mp[tmp] << endl;
    }
    return 0;
}
