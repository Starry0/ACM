#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int s[N],t[N], k, n, m, tmp;
map<int,int>mp1,mp2;
void fun(int x){
	mp2.clear();
	for(int i = x; i < x+k; i ++){
		mp2[s[i]]++;
	}
}
bool isUcloud(){
	map<int,int>::iterator it1 = mp1.begin();
	map<int,int>::iterator it2 = mp2.begin();
	for(; it1 != mp1.end(); ++it1,++it2){
		if((*it1) != (*it2)){
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d\n",&n);
	for(int i = 0; i < n; i ++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d",&k);
		//cin>>k;
		mp1.clear();
		for(int i = 0; i < k; i ++){
			scanf("%d",&tmp);
			mp1[tmp]++;
		}
		ll flag = 0;
		for(int i = 0; i <= n-k; i ++){
			fun(i);
			if(isUcloud()){
				flag++;
			}
		}
		printf("%lld\n",flag);
	}
	return 0;
}