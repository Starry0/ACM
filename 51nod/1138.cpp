#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
using namespace std;
set<int> st;
int main(){
	int n;
	cin >> n;
	for(int i = 2; i*(i+1) <= 2*n; i ++) {
		int ans = (2*n+i-i*i)/(2*i);
		if(ans > 0 && (2*n+i-i*i)%(2*i) == 0) st.insert(ans);
	}
	set<int> ::iterator it = st.begin();
	for(; it != st.end(); it ++) {
		printf("%d\n",(*it));
	}
	if(st.size() == 0) printf("No Solution\n");
	return 0;
}