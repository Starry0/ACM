#include<fstream>
#include<cstdio>
#include<string>
#include <iostream>
using namespace std;

string s;
char a[5005];
int p;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int i,len;
		cin>>s;
		len=s.size();
		for(i=0;i<len;++i)
		{
			if(s[i]=='@')
				p=0;
			else if(s[i]=='#' && p>0)
				--p;
			else if(s[i]!='#')
				a[++p]=s[i];
		}
		for(i=1;i<=p;++i)
			cout<<a[i];
		cout<<'\n';
	}
	return 0;
}
