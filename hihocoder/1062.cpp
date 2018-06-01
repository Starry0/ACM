#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
const int N = 110;
vector<string> fa, son, names;
map<string,int> mp;
int main(){
	int n, m, id = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++){
		string str1, str2;
		cin>>str1>>str2;
		fa.push_back(str1);
		son.push_back(str2);
		mp[str1] = mp[str2] = 0;
	}
	map<string,int>::iterator it;
	for(it=mp.begin(); it!=mp.end(); it++){
		names.push_back((*it).first);
		(*it).second = id++;
	}
	vector<int> pa(id,-1);
	for(int i = 0; i < n; i ++)
		pa[mp[son[i]]] = mp[fa[i]];
	scanf("%d",&m);
	for(int i = 0; i < m; i ++){
		string str1, str2;
		cin>>str1>>str2;
		int a = -1, b = -1;
		if(mp.count(str1))
			a = mp[str1];
		if(mp.count(str2))
			b = mp[str2];
		//cout << a << ' ' << b << endl;
		if(a == -1 || b == -1){
			if(str1 == str2) cout << str1 << endl;
			else cout << -1 << endl;
		}else{
			vector<int> mask(id,1);
			while(a>-1){
				mask[a] = 0;a = pa[a];
			}
			while(b>-1 && mask[b]) b = pa[b];
			if(b>-1)cout << names[b] << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}