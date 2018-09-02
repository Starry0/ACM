#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 1010;
int c[MAX][MAX];
void add(int x,int y,int k){
    for(int i = x; i < MAX; i += lowbit(i)){
        for(int j = y; j < MAX; j += lowbit(j)){
            c[i][j] += k;
        }
    }
}
int query(int x, int y){
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i)){
        for(int j = y; j > 0; j -= lowbit(j)){
            sum += c[i][j];
        }
    }
    return sum;
}
int main(){
	int n, m, q, l, r;
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> l >> r;
		add(l,r,1);
	}
	while(q--) {
		cin >> l >> r;
		printf("%d\n",query(r,r)-query(l-1,r)-query(r,l-1)+query(l-1,l-1));
	}
	return 0;
}