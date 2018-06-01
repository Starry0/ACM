#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 10100;
char str[MAX],str1[MAX];
int a[MAX][MAX];

int main(){
	while(scanf("%s %s",str+1,str1+1)!=EOF){
		int ans = 0;
		int i,j;
		for(i = 1; str[i]; i ++){
			for(j = 1; str1[j]; j ++){
				if(str[i] == str1[j]) a[i][j] = a[i-1][j-1] + 1;
				else a[i][j] = max(a[i-1][j],a[i][j-1]);	
			}
		}
		i--;j--;
		while(i > 0 && j > 0){
			if(str[i] == str1[j]){
				ans++;
				i--;j--;
			}else if(a[i-1][j] > a[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
		printf("%d\n",ans);
		memset(str,0,sizeof(str));
		memset(str1,0,sizeof(str1));
	}
	return 0;
}