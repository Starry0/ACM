#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	string str[4002];
	while(scanf("%d",&n)&&n){
		int cnt = 220;
		string s, ans;
		for(int i = 0; i < n; i++){
			cin>>str[i];
			if(str[i].size() < cnt){
				cnt = str[i].size();
				s = str[i];
			}
		}
		for(int i = cnt; i > 0; i--){
			for(int j = 0; j <= cnt-i; j++){
				string ss = s.substr(j,i);
				int k;
				for(k = 0; k < n; k ++){
					if(str[k].find(ss,0) == -1)
						break;
				}
				if(k == n && ss.size() > ans.size())
					ans = ss;
				else if(k==n && ss.size() == ans.size() && ans > ss)
					ans = ss;
			}
		}
		if(!ans.empty())
			printf("%s\n",ans.c_str());
		else printf("IDENTITY LOST\n");
	}
	return 0;
}