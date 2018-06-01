#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
char str[110];
set<string> ss;
int Min_index(char *ss){
	int i = 0,j = 1, k = 0;
	int len = strlen(ss);
	while(i<len && j<len && k<len){
		int t = ss[(j+k)%len]-ss[(i+k)%len];
		if(t == 0)k++;
		else{
			if(t>0) j+=k+1;
			else i+=k+1;
			k=0;
		}
		if(i==j)j++;
	}
	return min(i,j);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		string s,ans;
		for(int i = 0; i < n; i ++){
			scanf("%s",str);
			int k = Min_index(str);
			ans = str;
			s = ans.substr(k,ans.length()-k)+ans.substr(0,k);
			ss.insert(s);
		}
		printf("%d\n",ss.size());
		ss.clear();
	}
	return 0;
}