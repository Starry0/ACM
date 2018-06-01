#include <iostream>
using namespace std;
#define lowbit(x) x&(-x)
void unpdate(int x,int y){
	while(x < MAX){
		c[x]+=y;
		x += lowbit(x);
	}
}
int query(int x){
	int s = 0;
	while(x > 0){
		s +=c[x];
		x -= lowbit(x);
	}
	return x;
}

int main(){
	
	return 0;
}