#include<bits/stdc++.h>
using namespace std;
int a[1010];
struct Nod{
	int l,r;
}nod[1010];
int main(){
	int n, m, sum = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		sum += a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i ++){
		cin>>nod[i].l>>nod[i].r;
	}
	sort(a,a+n);
	cout << "----" << endl;
	if(sum > nod[m-1].l || a[0] > nod[0].l){
		cout << -1 << endl;
	}else{
		for(int i = 0; i < m; i ++){
			if(nod[i].l <= sum && sum <= nod[i].r || (nod[i-1].r < sum && sum < nod[i].l)){
				cout << sum << endl;
				return 0;
			}
		}
	}
	return 0;
}
