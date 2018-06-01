/*#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[11][110],str1[110],str2[110];

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < n; i ++)scanf("%s",str[i]);
		bool flag1 = false;
		for(int len = 60; len >= 3; len--){
			for(int i = 0; i <= 60-len; i ++){
				bool flag = true;
				strncpy(str1,str[0]+i,len);
				//if(len == 6)printf("%d %s\n",i,str1);
				for(int j = 1; j < n; j ++){
					if(strstr(str[j],str1)==NULL){
						flag=false;
						break;
					}
				}
				if(flag){
					flag1 = true;
					if(strlen(str1) > strlen(str2))strcpy(str2,str1);
					else if(strlen(str1) == strlen(str2) && strcmp(str1,str2)>0){
						strcpy(str2,str1);
					}
				}
				memset(str1,0,sizeof(str1));
			}
		}
		if(flag1)printf("%s\n",str2);
		else printf("no significant commonalities\n");
	}
	return 0;
}*/




#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
	int t,n,i,j;
	string str[11];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			cin>>str[i];
		string ans;
		for(i=3;i<=60;i++){
			for(j=0;j<=60-3;j++){
				bool flag = true;
				string s=str[0].substr(j,i);
				for(int k = 1; k < n; k ++)
					if(str[k].find(s) == string::npos){
						flag = false;
						break;
					}
				if(flag && s.size() > ans.size())
					ans = s;
				else if(flag && s.size() == ans.size() && s < ans)
					ans = s;
			}
		}
		if(!ans.empty())
			printf("%s\n",ans.c_str());
		else 
			printf("no significant commonalities\n");
	}
	return 0;
}