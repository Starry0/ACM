#include <iostream>
#include <string.h>
using namespace std;
const int Inf = 5e4+10;
int a[11], d[110];
int main(){
	memset(d,Inf,sizeof(d));
	for(int i = 1; i <= 10; i ++){
		cin >> a[i];
		d[i] = a[i];
	}
	// for(int i = 0; i <= 15; i ++){
	// 	cout << d[i] << ' ';
	// }
	// cout << endl;
	int res;
	cin >> res;
	d[0] = 0;
	for(int i = 1; i <= res; i ++){
		for(int j = 0; j <= i; j ++){
			if((i-j) > 0){
				d[i] = min(d[i],d[j] + d[i-j]);
			}
		}
	}
	cout << d[res]<< endl;
	return 0;
}
