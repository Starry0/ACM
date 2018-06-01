#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int N = 110;
const int INF = 1e8;
int g[N][N], dist[N], n, res;
bool vis[N];

void dijistra(int x){
    int pos = x;
    for(int i = 1; i <= res; i ++){
        dist[i] = g[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= res; i ++){
        int mins = INF;
        for(int j = 1; j <= res; j ++){
            if(!vis[j] && dist[j] < mins){
                pos = j;
                mins = dist[j];
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= res; j ++){
            if(!vis[j] && dist[j] > dist[pos] + g[pos][j]){
                dist[j] = dist[pos] + g[pos][j];
            }
        }
    }
}

map<string,int> mp;
int main(){
    string s, ss, start, end;
    while(cin >> n){
        mp.clear();
        res = 1;
        if(n == -1) break;
        cin >> start >> end;
        mp[start] = res++;mp[end] = res++;
        for(int i = 1; i <= N; i ++){
            for(int j = 1; j <= N; j++){
                if(i == j) g[i][j] = 0;
                else g[i][j] = INF;
            }
        }
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= n; i ++){
            int w;
            cin >> s >> ss >> w;
            if(!mp.count(s)) mp[s] = res++;
            if(!mp.count(ss)) mp[ss] = res++;
            g[mp[s]][mp[ss]] = g[mp[ss]][mp[s]] = w;
        }
        dijistra(mp[start]);
        int ans = dist[mp[end]];
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
