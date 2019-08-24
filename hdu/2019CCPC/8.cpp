//
// Created by starry on 2019/8/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N], n, k, t;
ll dp[N][2];

bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld%lld", &n, &k);
        for(int i = 0; i < n; i ++) {
            scanf("%lld", &a[i]);
        }
        ll tmp = 0;
        for(int i = 0; i < n; i ++) {
            tmp += a[i]/k;
            a[i] = a[i] % k;
//            MIN = min(MIN, a[i]);
        }
        ll result = k*(tmp+1);
        tmp = n - tmp - 1;
        sort(a,a+n,cmp);
        for(int i = 0; i < n; i ++) {
            if(a[i] == 0) break;
            if(tmp > 0) {
                result += k;
                tmp--;
            } else {
                result += a[i];
            }
        }
//        result = result - max(MIN, k) + MIN;
        printf("%lld\n",result);
    }
    return 0;
}

/*
 * str         abcdefg         abcdefg   bcdefg   cdefg   defg   efg  fg   g
 *
 * str[i] = str(i..len)
 * sa[i] = 表示排名第i的是前缀str(sa[i])
 * rank[i] =表示前缀str(i)的排名
 * height[i] = 排名为i和i-1的最大公共前缀长度
 *
 * */