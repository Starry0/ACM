/*#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int a[N], b[N];
char s[N];
int main() {
	int t, n, k;
	cin >>t;
	while(t--) {
		cin >> s >> k;
		int len = strlen(s);
		for(int i = 0; i < len; i ++) b[i] = a[i] = s[i]-'0';
		int cnt = 0;
		for(int i = 0; i < len; i ++) {
			int MAX = a[i], id1 = i, ans = 0, ans2 = 0, id2 = i;
			for(int j = i+1; j < len; j ++) {
				if(a[j] < a[i]) ans++;
				if(a[j] > MAX) {
					MAX = a[j];
					id2 = id1 = j;
					ans2 = 1;
				} else if(a[j] == MAX) {
					id2 = j;
					ans2++;
				}
			}
			if(MAX != a[i]) {
				// printf("%d %d %d\n",a[i],ans,ans2);
				if(ans==0) swap(a[i],a[id2]);
				else if(min(ans,k-cnt-1)+1 >= ans2) swap(a[i],a[id1]);
				else{
					int ans3 = min(ans,k-cnt-1), tmp = 0;
					// printf("%d %d %d %d\n",a[i],ans,ans2,ans3 );
					for(int j = i+1; j < len; j ++) {
						if(a[j] == MAX) tmp++;
						if(tmp == ans2-ans3) {
							swap(a[i],a[j]);
							break;
						}
					}
				}
				cnt++;
			}
			if(cnt == k) break;
		}
		int MAX = 0;
		for(int i = 0; i < len; i ++) {
			MAX = MAX*10 + a[i];
		}
		cnt = 0;
		for(int i = 0; i < len; i ++) {
			int MIN = b[i], id1 = i, id2 = i, ans1 = 0, ans2 = 0;
			for(int j = i+1; j < len; j ++) {
				if(b[j] > b[i]) ans1++;
				if(i == 0) {
					if(b[j] < MIN && b[j] != 0) {
						MIN = b[j];
						id2 = id1 = j;
						ans2 = 1;
					} else if(b[j] == MIN) {
						id2 = j;
						ans2 ++;
					}
				} else {
					if(b[j] < MIN) {
						MIN = b[j];
						id2 = id1 = j;
						ans2 = 1;
					} else if(b[j] == MIN) {
						id2 = j;
						ans2++;
					}
				}
			}

			if(MIN != b[i]) {
				if(ans1==0) swap(b[i],b[id2]);
				else if(min(ans1,k-cnt-1)+1 >= ans2) swap(b[i],b[id1]);
				else{
					int ans3 = min(ans1,k-cnt-1), tmp = 0;
				// printf("%d %d %d %d\n",b[i],ans1,ans2,ans3);
					for(int j = i+1; j < len; j ++) {
						if(b[j] == MIN) tmp++;
						if(tmp == ans2-ans3) {
							swap(b[i],b[j]);
							break;
						}
					}
				}
				cnt++;
			}
			if(cnt == k) break;
		}
		int MIN = 0;
		for(int i = 0; i < len; i ++) MIN = MIN*10 + b[i];
		printf("%d %d\n",MIN,MAX);
	}
	return 0;
}*/
// 998244353 
// 233944859

// 233944859 998544332
// 233944958 998544332


// #include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// const int N = 110;
// char s[N];
// int a[N], b[N];
// bool vis[N];
// int main() {
// 	int t, n, k;
// 	cin >> t;
// 	while(t--) {
// 		cin >> s >> k;
// 		int len = strlen(s);
// 		int MAX = 0, MIN;
// 		for(int i = 0; i < len; i ++) a[i] = s[i]-'0';
// 		for(int i = 0; i < len; i ++) b[i] = i, MAX = MAX*10+a[i];
// 		MIN = MAX;
// 		do{
// 			int ans = 0, ans1 = 0;
// 			for(int i = 0; i < len; i ++) {
// 				ans = ans*10+a[b[i]];
// 				vis[i] = 0;
// 			}
// 			for(int i = 0; i < len; i ++) {
// 				int tmp = i;
// 				if(vis[i]) continue;
// 				while(!vis[tmp]) {
// 					vis[tmp] = 1;
// 					tmp = b[tmp];
// 				}
// 				ans1++;
// 			}
// 			if(len-ans1 <= k && ans > MAX) MAX = ans;
// 			if(len-ans1 <= k && ans < MIN) MIN = ans;
// 		}while(next_permutation(b,b+len));
// 		printf("%d %d\n",MIN,MAX);
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<string> vs, v;
string s;
int k, len, t;
int main() {
	cin >> t;
	while(t--) {
		cin >> s >> k;
		len = s.length();
		vs.clear();
		vs.push_back(s);
		for(int i = 1; i <= min(k,len); i ++) {
			int cnt = vs.size();
			for(int j = 0; j < cnt; j ++) {
				s = vs[j];
				for(int x = 0; x < len; x ++) {
					for(int y = x+1; y < len; y ++) {
						swap(s[x],s[y]);
						if(s[0] != '0')vs.push_back(s);
						swap(s[x],s[y]);
					}
				}
			}
			sort(vs.begin(), vs.end());
			vs.erase(unique(vs.begin(),vs.end()), vs.end());
			if(vs.size() > 4) {
				v.clear();
				for(int i = 0; i < 2; i ++) v.push_back(vs[i]);
				for(int i = vs.size() -2; i <= vs.size() -1; i ++) v.push_back(vs[i]);
				vs.clear();
				for(auto ss : v) vs.push_back(ss);
			}
		}
		cout << vs[0] << ' ' << vs.back() << endl;
	}
	return 0;
}