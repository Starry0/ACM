#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 1100000;
int i, j, r, n, m, ansi, ansj, ansr;
long long ans;
long long p[maxn];

inline void make() {
    long long temp;
    ans = p[n];
    i = j = 1;
    while (i <= n) {
        while (j < i && p[j] <= p[i] - p[j])
            j++;
        temp = max(p[i] - p[j], p[j-1]);
        temp = max(p[n] - p[i], temp);
        if (temp < ans) {
            ans = temp;
            ansi = i;
            ansj = j;
        }
        i++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(p, 0, sizeof(p));
        scanf("%d", &n);
        for (i = 2; i <= n; i++) {
            scanf("%lld", &p[i]);
            p[i] += p[i-1];
        }
        make();
        printf("%lld\n", ans);
    }
    return 0;
}
