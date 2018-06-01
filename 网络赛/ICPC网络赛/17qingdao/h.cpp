#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char str[13][10] = { "rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep"
				, "monkey", "rooster", "dog", "pig"};
int main(){
	int t;
	cin >> t;
	while(t--) {
		char str1[10], str2[20];
		cin >> str1 >> str2;
		int index1, index2;
		for(int i = 0; i < 12; i ++) {
			if(strcmp(str[i],str1) == 0) {
				index1 = i;
				break;
			}
		}
		for(int i = 0; i < 12; i ++) {
			if(strcmp(str[i],str2) == 0) {
				index2 = i;
				break;
			}
		}
		if(index2 < index1) index2 += 12;
		int ans = abs(index1 - index2);
		if(ans == 0) printf("12\n");
		else printf("%d\n",ans);
	}
	return 0;
}