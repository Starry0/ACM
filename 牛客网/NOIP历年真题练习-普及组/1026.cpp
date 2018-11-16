#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2, s3;
	map<string,int> mp;
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s1.size(); i ++) if(s1[i] >= 'A' && s1[i] <= 'Z') s1[i] += 32;
	for(int i = 0; i < s2.size(); i ++) if(s2[i] >= 'A' && s2[i] <= 'Z') s2[i] += 32;
	// istringstream sss(s2);
	// while(sss >> s3) mp[s3]++;
	// if(mp[s1]) cout << mp[s1] << ' ' << s2.find(s1) << endl;
	// else cout << -1 << endl;
	bool f=false;
	int ans = 0, ans1 = 0;
    for(int i = 0; i < s2.size()-s1.size()+1; i ++) {
        if(s2.substr(i, s1.size())==s1 && !f && (s2[i-1]==' ' || i==0) && s2[i+s1.size()]==' ') {
            f = true;
            ans1 = i;
            ans++;
        } else if(s2.substr(i,s1.size())==s1 && (s2[i-1]==' ' || i==0) && s2[i+s1.size()]==' ')
                ans++;
    }
    if(ans==0) cout<<-1;
    else cout << ans << " " << ans1;
	return 0;
}