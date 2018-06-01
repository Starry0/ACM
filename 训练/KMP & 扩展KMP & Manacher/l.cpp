#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	int t,n,i,j,k;
	scanf("%d",&t);
	string str[110];
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			cin>>str[i];
		int ans = 0;
		for(i = str[0].size();i > 0; i--){
			for(j = 0; j <= str[0].size()-i; j++){
				string s = str[0].substr(j,i);
				string ss = s;
				reverse(s.begin(),s.end());
				for(k = 1; k < n; k ++)
					if(str[k].find(s,0) == -1 && str[k].find(ss,0) == -1){
						break;
					}
				if(k == n && s.size() > ans)
					ans = s.size();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}