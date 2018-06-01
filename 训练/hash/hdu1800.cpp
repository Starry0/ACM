#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr<<"";
	int n;
	while(cin>>n){
		mp.clear();
        string str;
        for(int i = 0; i < n; i ++){
            cin>>str;
            int j = 0;
            for(;j < str.size();j++)if(str[j] != '0') break;
            mp[str.substr(j)]++;
        }
        int ans = 0;
        for(auto m : mp){
            ans = max(ans , m.second);
        }
        cout<<ans<<endl;
	}
	return 0;
}