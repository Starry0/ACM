#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

const int maxn = 1E5 + 10;

int n,m,tp,stk[maxn];
bool vis[maxn];

vector <int> v[maxn];

void Dfs(int x)
{
    for (int i = 0; i < v[x].size(); i++)
    {
        int to = v[x][i];
        if (vis[to]) continue;
        vis[to] = 1; stk[++tp] = to;
        Dfs(to); return;
    }
}

int main()
{
    #ifdef DMC
        freopen("DMC.txt","r",stdin);
    #endif

    cin >> n >> m;
    while (m--)
    {
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y); v[y].push_back(x);
    }
    stk[tp = 1] = 1; vis[1] = 1; Dfs(1);
    //reverse(stk + 1,stk + tp + 1);
    //Dfs(1);
    cout << tp << endl;
    for (int i = 1; i < tp; i++) printf("%d ",stk[i]); cout << stk[tp] << endl;
    return 0;
}
