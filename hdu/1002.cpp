/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char str1[N], str2[N], str3[N];
char *add(char *str1, char *str2) {
	int len1 = strlen(str1), len2 = strlen(str2);
	int i = len1 - 1, j = len2 - 1, len3 = 0, flag = 0, x, y;
	while(i >= 0 || j >= 0) {
		if(i >= 0) x = str1[i] - '0';
		else x = 0;
		if(j >= 0) y = str2[i] - '0';
		else y = 0;
		if(x + y + flag > 9) {
			str3[len3++] = x + y + flag - 10 + '0';
			flag = 1;
		} else {
			str3[len3++] = x + y + flag + '0';
			flag = 0;
		}
		i--; j--;
	}
	if(flag) str3[len3++] = '1';
	for(int i = 0; i < len3/2; i ++) swap(str3[i], str3[len3-1-i]);
	return str3;
}
int main() {
	int t, cas = 1;
	cin >> t;
	while(t--) {
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		cin >> str1 >> str2;
		if(cas != 1) printf("\n");
		printf("Case %d:\n",cas++);
		printf("%s + %s = %s\n",str1, str2, add(str1,str2));
	}
	return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<char,int> m;
vector<int> v;
void f(string s,string ss){
    reverse(s.begin(),s.end());
	reverse(ss.begin(),ss.end());
    if(s.length()>ss.length())
        swap(s,ss);
    int a,b,sum,flags=0;
    for(int i=0;i<ss.length();++i){
        if(i>=s.length())
            a=0;
        else a=m[s[i]];
        b=m[ss[i]];
        sum=a+b+flags;
        if(sum>=10){
            sum-=10;
            flags=1;
        }
        else flags=0;
        v.push_back(sum);
    }
	
    if(flags)
        v.push_back(1);
    reverse(v.begin(),v.end());
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it;
    cout<<endl;
}
int main()
{
    for(int i=0;i<10;i++){
        m['0'+i]=i;
    }
    int t,i=1;
    string ss,s;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>s>>ss;
        printf("Case %d:\n",i++);
        cout<<s<<" + "<<ss<<" = ";
        f(s,ss);
        if(j!=t-1)
        cout<<endl;
        v.clear();
    }
    return 0;
}

for(int i = (lena>lenb ?lena:lenb)-1; i >= 0; i --) {
	if(lena >= 0) t+= (int)a[lena];
	if(lenb >= 0) t+= (int)b[lenb];
	lena--;lenb--;
}

*/

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int N =1e5+10;
char str1[N], str2[N], str3[N];
char * add(char *s, char *ss) {
	memset(str3, 0, sizeof(str3));
	int len1 = strlen(s)-1;
	int len2 = strlen(ss)-1;
	int len3 = 0, x, y, flag = 0;
	while(len1 >= 0 || len2 >= 0) {
		if(len1 >= 0) x = s[len1] - '0';
		else x = 0;
		if(len2 >= 0) y = ss[len2] - '0';
		else y = 0;
		str3[len3++] = (x+y+flag)%10 + '0';
		flag = (x+y+flag)/10;
		len2--;len1--;
	}
	for(int i = 0; i < len3/2; i ++) {
		swap(str3[i],str3[len3-i-1]);
	}
	return str3;
}

int main() {
	int t;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		if(ca != 1) printf("\n");
		printf("Case %d:\n",ca);
		cin >> str1 >> str2;
		printf("%s + %s = %s\n",str1,str2,add(str1,str2));
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
	}
	return 0;
}
