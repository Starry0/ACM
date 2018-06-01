#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
map<int,int> mp;
int main(){
    while(~scanf("%d",&n)){
        mp.clear();
        int k;
        for(int i = 0; i < n; i ++){
            int tmp, sum = 0;
            scanf("%d",&m);
            for(int i = 0 ; i < m; i ++){
                scanf("%d",&tmp);
                sum+=tmp;
                mp[sum] ++;
            }
            k = sum;
        }
        mp.erase(k);
        map<int,int>::iterator it = mp.begin();
        // for(; it != mp.end(); ++ it){
        //     cout << (*it).first << ' ' << (*it).second<<endl;
        // }
        // it = mp.begin();
        int maxn = (*it).second;
        it++;
        for(; it != mp.end(); ++it){
            int ans = (*it).second;
            if( ans > maxn ){
                maxn = (*it).second;
            }
        }
        printf("%d\n",n - maxn);
    }
    return 0;
}
