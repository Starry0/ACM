#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    vector<int> v[n+1];
    v[0].push_back(1);
    v[0].push_back(n-1);
    v[n-1].push_back(0);
    v[n-1].push_back(n-2);
    for(int i = 1; i < n -1; i ++){
        v[i].push_back((i+1)%n);
        v[i].push_back((i-1)%n);
    }
    int res = 1, cnt, ans = 1, minn, maxn, flag;
    for(int i = 1; i <= n; i ++){
        flag = 0;
        cnt = (res + k) % n;
        v[res].push_back(cnt);
        v[cnt].push_back(res);
        minn = min(res,cnt);
        maxn = max(res,cnt);
        for(int j = minn + 1; j < maxn; j ++){
            for(int k = 0, len = v[j].size(); k < len; k ++){
                if(v[j][k] > maxn || v[j][k] < minn) ans++;
            }
        }
        ans += flag + 1;
        if(i == 1) printf("%d",ans);
        else printf(" %d",ans);
        res = cnt;
    }
    printf("\n");
    return 0;
}
