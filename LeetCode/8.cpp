#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
class Solution {
public:
    int myAtoi(string str) {
    	int len = str.length();
    	int pos = 0, flag = 1;
    	char first = firstChar(str, pos);
    	if(first == ' ' || (!isOperator(first)&&!isNumber(first))) return 0;
    	if(isOperator(first)) {
    		if(first == '-') flag = -1;
    		else flag = 1;
    		pos ++;
    	}
    	if(pos >= len || !isNumber(str[pos])) return 0;
    	long long num = 0;
    	// printf("%d %d %c\n",flag, pos, str[pos]);
    	while(pos < len && isNumber(str[pos])) {
    		num = num*10 + str[pos]-'0';
    		pos ++;
    		if(num >= (1LL<<32)) break;
    	}
    	if(flag==-1 && num > (1LL<<31)) return -(1LL<<31);
    	if(flag==1 && num >= (1LL<<31)) return (1LL<<31)-1;
    	return num*flag;
    }
private:
	bool isOperator(char op) {
		return (op == '+' || op == '-');
	}
	bool isNumber(char ch) {
		return (ch >= '0' && ch <= '9');
	}
	char firstChar(string &str, int &pos) {
		while(pos < str.length() && str[pos] == ' ') pos ++;
		return pos<str.length()?str[pos]:' ';
	}
};

int main() {
	Solution sol;
	cout << sol.myAtoi("  123") << endl;
	cout << sol.myAtoi("42") << endl;
	cout << sol.myAtoi("   -42") << endl;
	cout << sol.myAtoi("4193 with words") << endl;
	cout << sol.myAtoi("words and 987") << endl;
	cout << sol.myAtoi("-91283472332") << endl;
	cout << sol.myAtoi("+1") << endl;
=======

int main() {
	Solution sol;

>>>>>>> 5eb63f73609acabccc5e780d632a2151158f888d
	return 0;
}