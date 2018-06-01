/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 500010;
int a[MAX],b[MAX];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int num, nn = 0, mm = 0;
		for(int i = 1; i <= n; i ++){
			scanf("%d",&num);
			if(num > 0){
				a[mm++] = num;
			}else b[nn++] = -num;
		}
		sort(a,a+mm,cmp);
		sort(b,b+nn,cmp);
		int i = 1,j=0,ans=1;
		int cnt = a[0], flag = 1;
		while(i < mm && j < nn){
			if(flag){
				while(j < nn){
					if(b[j] > cnt){
						j++;continue;
					}else{
						ans++;j++;
						cnt = b[j];
						flag = 0;
					}
				}
			}else{
				while(i < mm){
					if(a[i] > cnt){
						i++;continue;
					}else{
						ans++;i++;
						cnt = a[i];
						flag = 1;
					}
				}
			}
		}
		int ans1 = 1;
		i = 0; j = 1; flag = 0;
		cnt = b[0];
		while(i < mm && j < nn){
			if(flag){
				while(j < nn){
					if(b[j] > cnt){
						j++;continue;
					}else{
						cnt = b[j];
						j++;ans1++;
						flag=0;
					}
				}
			}else{
				while(i < mm){
					if(a[i] > cnt){
						i++;continue;
					}else{
						cnt = a[i];
						i++;ans1++;
						flag = 1;
					}
				}
			}
		}
		printf("%d\n",max(ans,ans1));
	}
	return 0;
}*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 500010;
int a[MAX],b[MAX];
bool cmp(int x, int y){
	return abs(x)>abs(y);
}


int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < n; i ++)scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		//for(int i = 0; i < n; i ++)printf("%d ",a[i]);
		int ans = 1;
		int flag = (a[0]>0)?1:0;
		int cnt = a[0];
		for(int i = 1; i < n; i ++){
			if(flag&&a[i]<0){
				ans++;flag=0;
			}else if(flag==0&&a[i]>0){
				ans++;flag=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
