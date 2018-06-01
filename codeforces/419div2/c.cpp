#include <iostream>
#include <stdio.h>
#define long long ll
using namespace std;
int a[110][110], n, m,b[110][110];
bool check(){
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(a[i][j] != 0){
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
//			scanf("%d",&a[i][j]);
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	int sum, flag = 1, i = 1,j = 1, ans = 0;
	if(n <= m){
		while(i <= n){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= m; k ++){
				if(!a[i][k]){
					flag = 0;
					break;
				}
			}
			if(flag){
				ans++;
				for(int k = 1; k <= m; k ++) a[i][k] -= 1;
			}else i++;
		}
		while(j <= m){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= n; k ++){
				if(!a[k][j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				ans ++;
				for(int k = 1; k <= n; k ++) a[k][j] -= 1;
			}else j++;
		}
	}else{
		while(j <= m){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= n; k ++){
				if(!a[k][j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				ans ++;
				for(int k = 1; k <= n; k ++) a[k][j] -= 1;
			}else j++;
		}
		while(i <= n){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= m; k ++){
				if(!a[i][k]){
					flag = 0;
					break;
				}
			}
			if(flag){
				ans++;
				for(int k = 1; k <= m; k ++) a[i][k] -= 1;
			}else i++;
		}
	}
	if(check()){
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	i = j = 1;
	if(n <= m){
		while(i <= n){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= m; k ++){
				if(!b[i][k]){
					flag = 0;
					break;
				}
			}
			if(flag){
				cout << "row " << i << endl;
				for(int k = 1; k <= m; k ++) b[i][k] -= 1;
			}else i++;
		}
		while(j <= m){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= n; k ++){
				if(!b[k][j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				cout << "col " << j << endl;
				for(int k = 1; k <= n; k ++) b[k][j] -= 1;
			}else j++;
		}
	}else{
		while(j <= m){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= n; k ++){
				if(!b[k][j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				cout << "col " << j << endl;
				for(int k = 1; k <= n; k ++) b[k][j] -= 1;
			}else j++;
		}
		while(i <= n){
			sum = 0;
			flag = 1;
			for(int k = 1; k <= m; k ++){
				if(!b[i][k]){
					flag = 0;
					break;
				}
			}
			if(flag){
				cout << "row " << i << endl;
				for(int k = 1; k <= m; k ++) b[i][k] -= 1;
			}else i++;
		}
	}
	return 0;
}