#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
const int N = 1e5+10;
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
	if(flag) str3[len3++] = '1';
    for(int i = 0; i < len3/2; i ++) {
        swap(str3[i],str3[len3-i-1]);
    }
    return str3;
}
char *sub(char *s, char *ss) {
    memset(str3, 0, sizeof(str3));
    int len1 = strlen(s)-1, len2 = strlen(ss)-1;
    int flag = 1, len3 = 0, x, y, cnt = 0;
    if(strcmp(s,ss) == 0){
        str3[len3++] = '0';
        return str3;
    }
    if(len1 < len2 || (len1==len2&&strcmp(s,ss)<0)) {
        swap(len1,len2);
        swap(s,ss);
        flag = 0;
    }
    while(len1 >= 0 || len2 >= 0) {
        if(len1 >= 0) x = s[len1--] - '0';
        else x = 0;
        if(len2 >= 0) y = ss[len2--] - '0';
        else y = 0;
        int ans = x-y+cnt;
        if(ans < 0) {
            str3[len3++] = ans+10+'0';
            cnt = -1;
        } else {
            str3[len3++] = ans+'0';
            cnt = 0;
        }
    }
	while(str3[len3-1] == '0') {
		str3[--len3] = '\0';
	}
    if(!flag) str3[len3++] = '-';
    for(int i = 0; i < len3/2; i ++) swap(str3[i], str3[len3-i-1]);
    return str3;
}
int main() {
	cin >> str1 >> str2;
	if(str1[0] != '-' && str2[0] != '-') {
		cout << add(str1,str2) << endl;
	} else if(str1[0] == '-' && str2[0] != '-') {
		cout << sub(str2,str1+1) << endl;
	} else if(str1[0] != '-' && str2[0] == '-') {
		cout << sub(str1, str2+1);
	} else {
		cout << "-" << add(str1+1,str2+1) << endl;
	}
	return 0;
}