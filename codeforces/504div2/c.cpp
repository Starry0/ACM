#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
char s[N];
int a[N], vis[N];
int main() {
   	int n, k;
   	cin >> n >> k;
   	cin >> s+1;
   	stack<int> st;
   	for(int i = 1; i <= n; i ++) {
   		if(s[i] == '(') st.push(i);
   		else {
   			int cnt = st.top();
   			st.pop();
   			a[cnt] = i;
   			a[i] = cnt;
   		}
   	}
   	int l = 1;
   	for(int i = 0; i < (n-k)/2; i ++) {
   		while(vis[l])l++;
  		vis[l] = vis[a[l]] = 1;
   	}
   	for(int i = 1; i <= n; i ++) {
   		if(!vis[i])printf("%c",s[i]);
   	}printf("\n");
    return 0;
}