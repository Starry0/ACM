#include <iostream>
#include <stdio.h>
#include <map>
#define ll long long
using namespace std;
map<string,string> mp;
int main(){
	string s,ss;
	char c;
	while(1){
		s = "";ss = "";
		if((c=getchar())=='\n')break;
		s += c;
		int i = 1;
		while(1){
			if((c=getchar())==' ')break;
			s += c;
		}
		//s = '\0';
		i = 0;
		while(1){
			if((c=getchar())=='\n')break;
			ss += c;
		}
		//ss[i]='\0';
		mp[ss] = s;
	}
	char sss[256];
	while(scanf("%s",sss)!=EOF){
		s = sss;
		if(mp.count(s)){
			s = mp[s];
			for(int i = 0,len = s.length(); i < len; i ++)
				putchar(s[i]);
			putchar('\n');
			//cout << mp[s] << endl;
		}else printf("eh\n");
	}
	return 0;
}