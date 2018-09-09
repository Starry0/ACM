#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
char str[N], str1[N*4];
map<char,int> mp;
int t, m, n, id, cnt, cnt1;
struct Nod{
    int id;
    Nod *next[2];
    Nod(){
        id = -1;
        next[0] = next[1] = NULL;
    }
};
void mkTrie(Nod *root,char *s, int id){
    Nod*p = root;
    for(int i = 0; s[i]; i ++){
        int a = s[i] - '0';
        if(p->next[a]==NULL)p->next[a] = new Nod;
        p = p->next[a];
    }
    p->id = id;
}
void find(Nod *root, char *s) {
	int ans = 0;
	Nod *p = root;
	for(int i = 0; i < cnt1; i ++) {
		int a = s[i]-'0';
		p = p->next[a];
		if(p->id != -1) {
			printf("%c",p->id);
			p = root; ans++;
		}
		if(ans == m) break;
	}
}
int main() {
	for(int i = 0; i < 10; i ++) mp['0'+i] = i;
	for(int i = 10; i < 16; i ++) mp['A'+i-10] = i;
	for(int i = 10; i < 16; i ++) mp['a'+i-10] = i;
	scanf("%d", &t);
	while(t--) {
		memset(str1, 0, sizeof(str1));
		memset(str, 0, sizeof(str));
		scanf("%d%d", &m, &n);
		char s[20];
		Nod *root = new Nod;
		for(int i = 1; i <= n; i ++) {
			scanf("%d%s",&id,s);
			mkTrie(root, s, id);
		}
		scanf("%s", str);
		cnt = 0, cnt1 = 0;
		for(int i = 0; str[i]; i ++) {
			int x = mp[str[i]];
			for(int j = 3; j >= 0; j --) {
				if((x>>j)&1) str1[cnt++] = '1';
				else str1[cnt++] = '0';
			}
		}
		str1[cnt] = '\0';
		// printf("%s\n",str1);
		for(int i = 8; i < cnt; i += 9) {
			int res = 0;
			for(int j = i-8; j < i; j ++) {
				if(str1[j] == '1') res++;
			}
			if((res%2==0&&str1[i]=='1') || (res%2&&str1[i]=='0')) {
				for(int j = i-8; j < i; j ++) {
					str1[cnt1++] = str1[j];
				}
			}
		}
		str1[cnt1] = '\0';
		// printf("%s\n",str1);
		find(root, str1); printf("\n");
	}
	return 0;
}