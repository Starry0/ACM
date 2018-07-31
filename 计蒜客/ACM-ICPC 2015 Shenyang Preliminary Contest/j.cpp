#include <bits/stdc++.h>
using namespace std;
const int mod = 530600414;
int main() {
	int ans = 27753;
	for(int i = 0; i*5 <= ans; i ++) {
		for(int j = 0; j*16 <= ans; j ++) {
			for(int k = 0; k*88<=ans; k ++) {
				for(int l = 0; l*352 <= ans; l ++) {
					for(int q = 1; q*1552 <= ans; q ++) {
						for(int p = 1; p *6512 <= ans; p ++) {
							int ans1 = i*5+j*16+k*88+l*352+q*1552+p*6512;
							if(ans1 > ans) break;
							if(ans1 == ans) {
								int ans2 = i*16+j*88+k*352+l*1552+q*6512+p*27753;
								int ans3 = i*88+j*352+k*1552+l*6512+q*27753+p*117392;
								if(ans2 == 117392 && ans3 == 497728)
								printf("%d %d %d %d %d %d\n",i,j,k,l,q,p);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}