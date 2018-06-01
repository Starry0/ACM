// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #include <vector>
// #include <set>
// using namespace std;
// const int N = 110;
// const int M = 1010;
// int dp[M], sco[N], cost[N], da[N];
// vector<int> vs[M];
// char a[N], b[N];
// void check(int x, int y, int p) {
//     memset(a, 0, sizeof(a));
//     memset(b, 0, sizeof(b));
//     int sum1 = 0, sum2 = 0, len1 = vs[x].size(), len2 = vs[y].size();
//     for(int i = 0; i < len1; i ++) {
//         sum1 += vs[x][i];
//         a[i] = vs[x][i] - '0';
//     }
//     for(int i = 0; i < len2; i ++) {
//         sum2 += vs[y][i];
//         b[i] = vs[y][i] - '0';
//     }
//     if(sum1 > sum2 + p) {
//         vs[x].clear();
//         for(int i = 0; i < len2; i ++) {
//             vs[x].push_back(vs[y][i]);
//         }
//         vs[x].push_back(p);
//     }else if(sum1 == sum2+p) {
//         b[len2] = p - '0';
//         sort(a,a+len1);sort(b,b+len2+1);
//         if(strcmp(a,b) > 0) {
//             vs[x].clear();
//             for(int i = 0; i < len2; i ++) {
//                 vs[x].push_back(vs[y][i]);
//             }
//             vs[x].push_back(p);
//         }
//     }
// }
// bool che(int x, int y) {
//     memset(a, 0, sizeof(a));
//     memset(b, 0, sizeof(b));
//     int sum1 = 0, sum2 = 0, len1 = vs[x].size(), len2 = vs[y].size();
//     for(int i = 0; i < len1; i ++) {
//         sum1 += vs[x][i];
//         a[i] = vs[x][i] - '0';
//     }
//     for(int i = 0; i < len2; i ++) {
//         sum2 += vs[y][i];
//         b[i] = vs[y][i] - '0';
//     }
//     if(sum1 > sum2) {
//         return true;
//     }else if(sum1 == sum2) {
//         sort(a,a+len1);sort(b,b+len2);
//         if(strcmp(a,b) > 0) {
//             return true;
//         }
//     }
//     return false;
// }
// int main() {
//     int t, cas = 1;
//     cin>>t;
//     while(t--) {
//         int b, n;
//         cin >> b >> n;
//         for(int i = 1; i <= n; i ++) {
//             cin >> sco[i] >> cost[i];
//         }
//         for(int i = 0; i <= b; i ++) dp[i] = -1000000;
//         dp[0] = 0;
//         for(int i = 1; i <= n; i ++) {
//             for(int j = b; j >= cost[i]; j --) {
//                 if(dp[j] < dp[j - cost[i]] + sco[i]) {
//                     dp[j] = dp[j - cost[i]] + sco[i];
//                     vs[j].clear();
//                     for(int l = 0; l < vs[j-cost[i]].size(); l ++) {
//                         vs[j].push_back(vs[j-cost[i]][l]);
//                     }
//                     vs[j].push_back(i);
//                 }
//                 else if(dp[j] == dp[j - cost[i]] + sco[i]) {
//                     check(j, j - cost[i], i);
//                 }
// //                dp[j] = max(dp[j], dp[j-cost[i]] + sco[i]);
//             }
//         }
//         int MC = 0, MSCO = 0;
//         for(int i = 0; i <= b; i ++) {
//             if(dp[i] > MSCO) {
//                 MSCO = dp[i];
//                 MC = i;
//             } else if(dp[i] == MSCO) {
//                 if(che(MC,i)) {
//                     MC = i;
//                 }
//             }
//         }
//         printf("Case #%d:\n",cas++);
//         printf("%d %d\n", MSCO, MC);
//         int len = vs[MC].size();
//         for(int i = 0; i < len; i ++) {
//             da[i] = vs[MC][i];
//         }
//         sort(da,da+len);
//         for(int i = 0; i < len; i ++) {
//             printf("%d%c",da[i],(i==(len-1)?'\n':' '));
//         }
//         for(int i = 0; i <= b; i ++) vs[i].clear();
//     }
//     return 0;
// }



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1100;
const int M = 1010;
int cost[N], sco[N], dp[M], c[N];
vector<int> vs[M], tmp;
void init() {
    for(int i = 0; i < M; i ++) vs[i].clear();
    memset(cost, 0, sizeof(cost));
    memset(sco, 0, sizeof(sco));
    memset(dp,0,sizeof(dp));
}
char a[N], b[N];
void check(int x, int y, int p) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int sum1 = 0, sum2 = 0, len1 = vs[x].size(), len2 = vs[y].size();
    for(int i = 0; i < len1; i ++) {
        sum1 += vs[x][i];
        a[i] = vs[x][i]-'0';
    }
    for(int i = 0; i < len2; i ++) {
        sum2 += vs[y][i];
        b[i] = vs[y][i] - '0';
    }
    sum2 += p;b[len2] = p - '0';
    if(sum1 > sum2) {
        tmp.clear();
        for(int i = 0; i < len2; i ++) {
            tmp.push_back(vs[y][i]);
        }
        tmp.push_back(p);
        vs[x].clear();
        for(int i = 0; i < tmp.size(); i ++) {
            vs[x].push_back(tmp[i]);
        }
    }else if(sum1 == sum2) {
        sort(a, a+len1); sort(b, b+len2+1);
        if(strcmp(a,b) > 0) {
            tmp.clear();
            for(int i = 0; i < len2; i ++) {
                tmp.push_back(vs[y][i]);
            }
            tmp.push_back(p);
            vs[x].clear();
            for(int i = 0; i < tmp.size(); i ++) {
                vs[x].push_back(tmp[i]);
            }
        }
    }
}
bool check1(int x, int y) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int sum1 = 0, sum2 = 0, len1 = vs[x].size(), len2 = vs[y].size();
    for(int i = 0; i < len1; i ++) {
        sum1 += vs[x][i];
        a[i] = vs[x][i] - '0';
    }
    for(int i = 0; i < len2; i ++) {
        sum2 += vs[y][i];
        b[i] = vs[y][i] - '0';
    }
    if(sum1 < sum2) {
        return true;
    } else if(sum1 == sum2) {
        if(strcmp(a, b) < 0) {
            return true;
        }
    }
    return false;
}
int main() {
    int t, cas = 1;
    cin >> t;
    while(t--) {
        init();
        int b, n;
        cin >> b >> n;
        for(int i = 1; i <= n; i ++) cin >> sco[i] >> cost[i];
        for(int i = 1; i <= n; i ++) {
            for(int j = b; j >= cost[i]; j --) {
                if(dp[j] < dp[j-cost[i]] + sco[i]) {
                    // printf("%d\n",dp[j]);
                    dp[j] = dp[j-cost[i]] + sco[i];
                    tmp.clear();
                    for(int k = 0; k < vs[j-cost[i]].size(); k ++) {
                        tmp.push_back(vs[j-cost[i]][k]);
                    }
                    tmp.push_back(i);
                    vs[j].clear();
                    for(int k = 0; k < tmp.size(); k ++) {
                        vs[j].push_back(tmp[k]);
                    }
                }else if(dp[j] == dp[j-cost[i]] + sco[i]) {
                    check(j,j-cost[i],i);
                }
            }
        }
        int MC = 0, MSCo = 0;
        for(int i = 0; i <= b; i ++) {
            if(dp[i] > MSCo) {
                MSCo = dp[i];
                MC = i;
            } else if(dp[i] == MSCo) {
                if(check1(i, MC)) {
                    MC = i;
                }
            }
        }
        printf("Case #%d:\n",cas++);
        printf("%d %d\n",MSCo, MC);
        memset(c, 0, sizeof(c));
        int cnt = 0;
        for(int i = 0; i < vs[MC].size(); i ++) {
            c[cnt++] = vs[MC][i];
        }
        sort(c, c+cnt);
        for(int i = 0; i < cnt; i ++) {
            printf("%d%c",c[i],(i == (cnt-1) ? '\n': ' '));
        }
    }
    return 0;
}
/*
10 
0 
4 
1 0 
2 0 
3 0 
4 0 
Case #1: 
    10 0 
    1 2 3 4*/