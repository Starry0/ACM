#include <bits/stdc++.h>
#define ll long long
using namespace std;
char a[17][110];
int main(){
    int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m+2; j ++){
			cin >> a[i][j];
		}
	}
	int k;
	for(k = 1; k <= n; k ++){
		bool flag = false;
		for(int j = 1; j <= m+2; j ++){
			if(a[k][j] == '1'){
				flag = true;
			}
		}
		if(flag) break;
	}
	int ans = n-k, cou = 1, mid = (m+2+1)/2;
	for(int i = n; i >= k; i --){
		int l = 1, r = m+2;
		while(a[i][l] == '0') l++;
		while(a[i][r] == '0') r--;
		if(cou){
			if(l <= mid && r <= mid){
				ans += (r*2-3);
				cou = 1;
			}else{
				ans += (m+1);
				cou = 0;
			}
		}else{
			if(l > mid && r > mid){
				ans += (r*2-3);
				cou = 1;
			}else{
				ans += (m+1);
				cou = 0;
			}
		}
	}
    return 0;
}
