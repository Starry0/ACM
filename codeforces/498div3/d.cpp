/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n;
set<char> st;
char str1[N], str2[N];
int main() {
	cin >> n >> str1+1 >> str2+1;
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(str1[i] != str2[i]) {
			if(i == n-i+1) {
				str1[i] = str2[i];
				ans++;
				continue;
			}
			if(str1[n-i+1] != str2[n-i+1]) {
				st.clear();
				st.insert(str1[i]);
				st.insert(str2[i]);
				st.insert(str1[n-i+1]);
				st.insert(str2[n-i+1]);
				if(st.size() == 3) {
					ans += 2;
				} else if(st.size() == 4) {
					ans += 2;
				}
				str1[i] = str2[i];
				str1[n-i+1] = str2[n-i+1];
			} else {
				ans++;
				str1[i] = str2[i];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n;
set<char> st;
char str1[N], str2[N];
int main() {
	cin >> n >> str1+1 >> str2+1;
	int ans = 0;
	for(int i = 1, j = n; i < j; i ++, j--) {
		int now = min((str1[i]!=str2[i])+(str1[j]!=str2[j]), (str1[i]!=str2[j])+(str1[j]!=str2[i]));
		if(str2[i]==str2[j]) now = min(now, int(str1[i]!=str1[j]));
		ans += now;
	}
	ans += (n%2==1&&str1[(n+1)/2]!=str2[(n+1)/2]);
	printf("%d\n",ans);
	return 0;
}




// a a        0
// b b

// a b        0
// b a

// a c      1     交换a b 将c变为b
// b a

// a b      1
// b c

// a a         2       将a变b，和c
// b c

// a b        2
// c d