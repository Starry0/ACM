#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	char s[110];
	int a[110], k = 0;
	int n;
	cin >>n>>s;
	int cnt = 0;
	for(int i = n-1; i >= 0; i--){
		if(i == n-1 && s[i] == '0'){
			a[k++] = 0;
			continue;
		}
		if(s[i] == '1'){
			cnt++;
		}else if(s[i] == '0' && cnt != 0){
			a[k++] = cnt;
			cnt = 0;
		}else if(s[i] == '0' && cnt == 0){
			a[k++] = 0;
		}
	}
	if(cnt)cout << cnt;
	for(int i = k-1; i >= 0; i--)
		cout << a[i];
	cout << endl;
	return 0;
}