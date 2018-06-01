#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
map<string,string> mp;
set<string> s;
vector<string> v;
int main()
{
    int q, ans = 0;
    cin >> q;
    string ss,ss1;
    while(q--){
        cin >> ss >> ss1;
        s.insert(ss1);
        if(!s.count(ss)) {
            ans ++;
            v.push_back(ss);
        }
        mp[ss] = ss1;
    }

    cout << ans << endl;
    for(int i = 0; i < v.size(); i++){
        string sss = v[i];
        while(mp.count(mp[sss])) sss = mp[sss];
        cout << v[i] << " " << mp[sss] << endl;
    }
    return 0;
}
