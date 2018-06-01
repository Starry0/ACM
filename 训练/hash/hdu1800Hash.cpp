#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e5+7;
int Hash[Mod], cnt[Mod];
unsigned int ELFHash(char *str){
	unsigned int h = 0;
	unsigned int x;
	while(*str){
		h = (h << 4) + *str++;
		x = h & 0xF0000000L;
		if(x){
			h ^= x>>24;
			h &= ~x;
		}
	}
	return h & 0x7FFFFFFF;
}
int Hashhit(char *str){
	while(*str == '0') str++;
	int k = ELFHash(str);
	int t = k % Mod;
	while(Hash[t] && Hash[t] != k) 
		t = (t + 10) % Mod;
	if(Hash[t] == 0) Hash[t] = k;
	return ++cnt[t];
}
int main(){
	int n;
	char str[33];
	while(~scanf("%d",&n)){
		memset(Hash,0,sizeof(Hash));
		memset(cnt,0,sizeof(cnt));
		int ans = 0;
		for(int i = 0 ; i < n; i ++){
			scanf("%s",str);
			ans = max(ans,Hashhit(str));
		}
		printf("%d\n",ans);
	}
	return 0;
}