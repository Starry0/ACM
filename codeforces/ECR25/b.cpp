#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
char str[12][12];
int main(){
	for(int i = 1; i <= 10; i ++)scanf("%s",str[i]+1);
	//for(int i = 1; i <= 10; i ++)cout << str[i]+1<<endl;
	int flag = 0,ans = 0,ans1= 0;
	for(int i = 1; i <= 10; i ++){
		for(int j = 1; j <= 10;j ++){
			if(j <= 6){
				for(int k = 0; k < 5;k++){
					if(str[i][j+k]=='X')ans++;
					if(str[i][j+k]=='.')ans1++;
				}
				if(ans==4&&ans1==1)flag=1;
				ans=ans1=0;
				if(i <= 6){
					for(int k = 0; k < 5; k ++){
						if(str[i+k][j+k]=='X')ans++;
						if(str[i+k][j+k]=='.')ans1++;
					}
				}
				if(ans==4&&ans1==1)flag=1;
				ans=ans1=0;
			}
			if(i <= 6){
				for(int k = 0; k < 5; k ++){
					if(str[i+k][j]=='X')ans++;
					if(str[i+k][j]=='.')ans1++;
				}
				if(ans==4&&ans1==1)flag=1;
				ans=ans1=0;
				if(j>=5){
					for(int k = 0; k < 5; k ++){
						if(str[i+k][j-k]=='X')ans++;
						if(str[i+k][j-k]=='.')ans1++;
					}
				}
				if(ans==4&&ans1==1)flag=1;
				ans=ans1=0;
			}
		}
	}
	if(flag)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}