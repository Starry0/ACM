#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], b[N];
int main() {
	int n, r, w, sum = 0;
	cin >> n >> r;
	for(int i = 0; i < n; i ++) cin >> a[i], sum += a[i];
	int l = sum/r, R = sum, ans = sum;
	sort(a,a+n);
	while(l <= R){
		w = (l+R)>>1;
		set<int> st;
		int tmp = 0, flag = 1;
		for(int i = 0; i < r; i ++) b[i] = 0;
		for(int i = n-1; i >= 0; i --) {
			int cnt = 0;
			while(cnt < r && b[tmp]+a[i] > w) {
				cnt++;
				tmp = (tmp+1)%r;
			}
			if(cnt < r) {
				b[tmp] += a[i];
			} else {
				flag = 0;
				break;
			}
		}
		if(flag) {
			for(int i = 0; i < r; i ++) st.insert(b[i]);
			if(st.size() == r) {
				if(w < ans) {
					ans = w; 
					R = w-1;
				} else l = w+1;
			} else l = w+1;
		} else l = w+1;
		st.clear();
	}
	printf("%d\n",ans);
	return 0;
}