#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char str[N];
int nex[N];
void init(){
	memset(nex, 0, sizeof(nex));
    int j = nex[0] = -1, i = 0;
    int len = strlen(str);
    while(i < len){
        if(j == -1 || str[i] == str[j]){
            nex[++i] = ++j;
        }else j = nex[j];
    }
}
int main() {
	int n;
	cin >> n;
	while(n--) {
		memset(str, 0, sizeof(str));
		scanf("%s",str);
		init();
		int len = strlen(str);
		printf("%d\n",len/(len-nex[len]));
	}
	return 0;
}