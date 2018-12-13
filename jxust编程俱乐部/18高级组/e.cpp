#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int main() {
	cin >> s;
	bool flag = true;
	for(int i = 0; i < s.length(); i ++) {
		if(!((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')||s[i]>='A'&&s[i]<='F')) 
			flag = false;
	}
	if(flag&&s.length()==32) printf("Yes\n");
	else printf("No\n");
	return 0;
}