#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	int t, x1, y1, x2, y2;
	char ch1, ch2;
	scanf("%d", &t);
	while(t--) {
		cin >> ch1 >> y1 >> ch2 >> y2;
		x1 = ch1 - 'A' + 1;
		x2 = ch2 - 'A' + 1;
		if(ch1 == ch2 && y1 == y2) printf("0 %c %d\n",ch1, y1);
		else if((x1+y1)%2 != (x2+y2)%2) printf("Impossible\n");
		else if((x1+y1)&1){
			int ans = 0, x3 = x1, y3 = y1, x4 = x2, y4 = y2;
			if(x3+y3 != 9) {
				ans ++;
				if(x3+y3 < 9) {
					while(x3+y3 !=9) x3++,y3++;
				} else {
					while(x3+y3 !=9) x3--,y3--;
				}
			}
			if(x4+y4 != 9) {
				ans ++;
				if(x4+y4 < 9) {
					while(x4+y4 !=9) x4++,y4++;
				} else {
					while(x4+y4 !=9) x4--,y4--;
				}
			}
			if(x3 != x4) ans++;
			printf("%d %c %d",ans,x1+'A'-1,y1);
			if(x1+y1 != 9) printf(" %c %d",x3+'A'-1,y3);
			if(x3 != x4) printf(" %c %d",x4+'A'-1,y4);
			if(x2 != x4) printf(" %c %d",x2+'A'-1,y2);
			printf("\n");
		} else{
			int ans = 0, x3 = x1, y3 = y1, x4 = x2, y4 = y2;
			if(x3+y3 != 8) {
				ans ++;
				if(x3+y3 < 8) {
					while(x3+y3 !=8) x3++,y3++;
				} else {
					while(x3+y3 !=8) x3--,y3--;
				}
			}
			if(x4+y4 != 8) {
				ans ++;
				if(x4+y4 < 8) {
					while(x4+y4 !=8) x4++,y4++;
				} else {
					while(x4+y4 !=8) x4--,y4--;
				}
			}
			if(x3 != x4) ans++;
			printf("%d %c %d",ans,x1+'A'-1,y1);
			if(x1+y1 != 8) printf(" %c %d",x3+'A'-1,y3);
			if(x3 != x4) printf(" %c %d",x4+'A'-1,y4);
			if(x2 != x4) printf(" %c %d",x2+'A'-1,y2);
			printf("\n");
		}
	}
	return 0;
}