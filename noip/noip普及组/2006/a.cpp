#include <bits/stdc++.h>
using namespace std;
int a[1010], b[110];
int main() {
	int n, x; 
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		a[x] ++;
	}
	int ans = 0, k = 0;
	for(int i = 0; i < 1001; i ++) {
		if(a[i]){
			ans++;
			b[k++] = i;
		}
	}
	printf("%d\n",ans);
	for(int i = 0; i < 1001; i ++) {
		if(a[i]) printf("%d ",i);
	}
	printf("\n");
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
set<int> st;
int main() {
	int x, ans = 0, n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		st.insert(x);
	}
	set<int> :: iterator it = st.begin();
	cout << st.size() << endl;
	for(; it != st.end(); ++ it) {
		printf("%d ",(*it));
	}
	cout << endl;
	return 0;
}*/
/*
#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	for(int i = 0; i < n; i ++) {
		printf("%d%c",a[i],(i==n-1)?'\n':' ');
	}
	n=unique(a,a+n)-a;
	cout << n << endl;
	for(int i = 0; i < n; i ++) {
		printf("%d%c",a[i],(i==n-1)?'\n':' ');
	}
	return 0;
}*/
