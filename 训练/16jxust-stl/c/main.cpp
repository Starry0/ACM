#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> mp;
int main()
{
    int n, m, c;
    while(scanf("%d%d",&n,&m)!=EOF){
        mp.clear();
        for(int i = 0; i < n; i++){
            scanf("%d",&c);
            mp[c] ++;
        }
        while(m--){
            scanf("%d",&c);
            cout << mp[c] << endl;
            mp[c] = 0;
        }
    }
    return 0;
}
