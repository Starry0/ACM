#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 1000010;
char str[MAX];
int nex[MAX];
void init(){
	int j = nex[0] = -1, i = 0;
	int len = strlen(str);
	while(i < len){
		if(j == -1 || str[i] == str[j]) nex[++i] = ++j;
		else j = nex[j];
	}
}
int minAndMax(bool flag){
	int i = 0, j = 1, k = 0;
	int len = strlen(str);
	while(i<len && j<len && k<len){
		int t = str[(j+k)%len]-str[(i+k)%len];
		if(t == 0) k++;
		else {
			if(flag){
				if(t>0)j+=k+1;
				else i+=k+1;
			}else{
				if(t>0)i+=k+1;
				else j+=k+1;
			}
			if(i==j)j++;
			k=0;
		}
	}
	return min(j,i);
}
int main(){
	while(scanf("%s",str)!=EOF){
		init();
		int MIN = minAndMax(true);
		int MAX = minAndMax(false);
		int len = strlen(str);
		int cnt = len-nex[len];
		int ans = len%cnt?1:len/cnt;
		printf("%d %d %d %d\n",MIN+1,ans,MAX+1,ans);
		memset(str,0,sizeof(str));
	}
	return 0;
}