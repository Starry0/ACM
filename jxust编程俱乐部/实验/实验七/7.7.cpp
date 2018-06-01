#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
map<string,int> mp;
int main(){
	string str;
	while(cin >> str)mp[str]++;
	printf("%d\n",mp.size());
	return 0;
}