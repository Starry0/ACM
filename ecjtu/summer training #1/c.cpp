#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> P;
map<int,int> xx,yy;
map<P,int> s;
map<int,int>::iterator it1;
map<P,int>::iterator it2;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        int a,b;
        scanf("%d%d",&a,&b);
        xx[a]++;yy[b]++;
        s[P(a,b)]++;
    }
    ll ans = 0;
    for(it1 = xx.begin(); it1!=xx.end(); it1++){
        ans += (ll)(*it1).second*((*it1).second-1)/2;
    }
    for(it1 = yy.begin(); it1!=yy.end(); it1++){
        ans += (ll)(*it1).second*((*it1).second-1)/2;
    }
    for(it2 = s.begin(); it2!=s.end(); ++it2){
        ans -= (ll)(*it2).second*((*it2).second-1)/2;
    }
    cout << ans << endl;
    return 0;
}
