#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
const int M = 2e3+10;
struct Nod{
	int x, y;
}nod[M];
bool cmp(Nod a, Nod b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}
int s[N][22], h[N], n, k, m;
int minCheck(int l, int r){
	for(int i = 1; i <= 20; i ++){
		if(s[l-1][i] != s[r][i]){
			return i;
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n; i ++){
		scanf("%d",&h[i]);
		for(int j = 0; j <= 20; j ++){
			s[i][j] = s[i-1][j];
		}
		s[i][h[i]]++;
	} 
	scanf("%d",&m);
	//cout << "----" << endl;
	for(int i = 1; i <= m; i ++){
		scanf("%d %d",&nod[i].x,&nod[i].y);
	}
	sort(nod+1,nod+1+m,cmp);
	int ans = 0;
	for(int i = 1; i <= m; i ++){
		for(int j = i + 1; j <= m; j ++){
			int x1 = nod[i].x, y1 = nod[i].y;
			int x2 = nod[j].x, y2 = nod[j].y;
			int cnt;
			if(x1 == x2){
				if(abs(y1-y2) <= k) ans++;
			}else{
				cnt = x2 - x1 + y1 + y2 - 2*minCheck(x1,x2);
				if(cnt <= k) ans ++;
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}