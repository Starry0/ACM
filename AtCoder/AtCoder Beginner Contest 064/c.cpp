#include <bits/stdc++.h>
using namespace std;
int n,a[10];
int main(){
	int tmp;
	for(cin>>n;n--;){
		cin >> tmp;
		if(tmp < 400) a[1] = 1;
		else if(tmp < 800) a[2] = 1;
		else if(tmp < 1200) a[3] = 1;
		else if(tmp < 1600) a[4] = 1;
		else if(tmp < 2000) a[5] = 1;
		else if(tmp < 2400) a[6] = 1;
		else if(tmp < 2800) a[7] = 1;
		else if(tmp < 3200) a[8] = 1;
		else a[9]++;
	}
	int minn = 0, maxn = a[9];
	for(int i = 1; i < 9; i ++){
		if(a[i]) minn++;
	}
	cout << max(1,minn) << ' ' << minn + maxn << endl;
	return 0;
}