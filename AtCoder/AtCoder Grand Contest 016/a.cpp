#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[110], ss[110];
bool check(int x){
	for(int i = 0; i < strlen(ss)-x-1; i ++){
		if(ss[i] != ss[i+1])return false;
	}
	return true;
}
int fun(int x){
	strcpy(ss,s);
	int cnt = 0;
	int len = strlen(ss);
	while(1){
		if(check(cnt))break;
		for(int i = 0; i <len-cnt-1; i ++){
			if(ss[i+1] == ('a'+x)){
				ss[i] = 'a'+x;
			}else ss[i] = ss[i];
		}
		cnt++;
	}
	return cnt;
}

int main(){
	cin >> s;
	int ans = strlen(s)/2;
	for(int i = 0; i < 26; i ++){
		//cout << i <<' ' << fun(i) << endl;
		ans = min(ans,fun(i));
	}
	cout << ans << endl;
	return 0;
}