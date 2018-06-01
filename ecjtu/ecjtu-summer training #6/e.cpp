#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#define ll long long
using namespace std;
string s[110],ss[110],sss[110];

int main(){
	int t,n;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		map<string,int> mp;
		//vector<string> vs[110];
		set<string> st,st1[110];
		for(int i = 0; i < n; i ++){
			cin>>s[i]>>ss[i]>>sss[i];
			//st.insert(s[i]);
			//st.insert(ss[i]);
			//st.insert(sss[i]);
		}
		mp["Ahmad"] = 1;
		st1[0].insert("Ahmad");
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				if(st1[i].count(s[j])){
					if(mp[ss[j]] == 0){
						st1[i+1].insert(ss[j]);
						mp[ss[j]] = 1;
					}
					if(mp[sss[j]]==0){
						st1[i+1].insert(sss[j]);
						mp[sss[j]] = 1;
					}
				}
				if(st1[i].count(ss[j])){
					if(mp[sss[j]] == 0){
						st1[i+1].insert(sss[j]);
						mp[sss[j]] = 1;
					}
					if(mp[s[j]]==0){
						st1[i+1].insert(s[j]);
						mp[s[j]] = 1;
					}
				}
				if(st1[i].count(sss[j])){
					if(mp[ss[j]] == 0){
						st1[i+1].insert(ss[j]);
						mp[ss[j]] = 1;
					}
					if(mp[s[j]]==0){
						st1[i+1].insert(s[j]);
						mp[s[j]] = 1;
					}
				}
			}
		}
		for(int i = 0; i < n; i ++){
			if(mp[s[i]]==0)st.insert(s[i]);
			if(mp[ss[i]]==0)st.insert(ss[i]);
			if(mp[sss[i]]==0)st.insert(sss[i]);
			mp[s[i]]=1;mp[ss[i]]=1;mp[sss[i]]=1;
		}
		cout << mp.size() << endl;
		set<string>::iterator it;
		for(int i = 0; i <= n; i ++){
			if(st1[i].size() == 0)break;
			for(it = st1[i].begin(); it != st1[i].end(); ++it){
				cout << (*it) << ' ' << i << endl;
			}
		}
		for(it = st.begin(); it != st.end(); ++it){
			cout << (*it) << " undefined\n";
		}
	}
	return 0;
}