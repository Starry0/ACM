#include <bits/stdc++.h>
using namespace std;
char str[110];
int n;
int main(){
	cin >> n >> str;
	if(str[0] == 'S' && str[n-1] == 'F') printf("YES\n");
	else printf("NO\n");
	return 0;
}