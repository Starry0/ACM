/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1010];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i ++){
			//scanf("%d",a[i]);
			cin>>a[i];
		}
		ll ans = 0;
		for(int i =0; i < n; i ++){
			for(int j = i+1; j <n; j ++){
				if(a[i]>a[j]){
					ans++;
					swap(a[i],a[j]);
				}
			}
		}
		cout << ans << endl;
		//printf("")
	}
	return 0;
}*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1010];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i ++){
			//scanf("%d",a[i]);
			cin>>a[i];
		}
		ll ans = 0;
		for(int i =1; i < n; i ++){
			for(int j = 0; j <n-1; j ++){
				if(a[j]>a[j+1]){
					ans++;
					swap(a[j],a[j+1]);
				}
			}
		}
		cout << ans << endl;
		//printf("")
	}
	return 0;
}