#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string.h>
#define INF 0x3f3f3f3f
const int N = 200010;
using namespace std;
char str[N];
int nex[N], a[N],b[N];
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
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--) {
		scanf("%s",str);
		int len = strlen(str);
		init();
		int len1 = len - (nex[len-1]+1);
		//printf("%d %d\n",len,len1);
		printf("%d\n",len/len1);
	}
	return 0;
}