#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5e5+10;
int m, a[N], x;
int main(){
	char c;
	while(scanf("%d",&m)!=EOF){
		int flag = -1, ans = 0, cnt = 0;
		for(int i = 1; i <= m; i ++){
			//cin >> c;
			getchar();
			scanf("%c",&c);
			if(c == 'I'){
				scanf("%d",&x);
				if(cnt)continue;
				if(a[x] == 1){
					flag = i;
					cnt = 1;
				}
				a[x] = 1;
			}else if(c == 'O'){
				scanf("%d",&x);
				if(cnt)continue;
				if(a[x] == 0){
					if(ans == 0){
						flag = i;
						cnt = 1;
					}else{
						ans--;
					}
				}else a[x] = 0;
			}else if(c == '?'){
				if(cnt)continue;
				ans++;
			}
		}
		printf("%d\n",flag);
	}
	return 0;
}