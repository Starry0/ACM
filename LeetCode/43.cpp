#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) return "";
		int *num = new int[num1.size()+num2.size()];
		memset(num, 0, sizeof(int)*(num1.size()+num2.size()));
		int len1 = num1.length(), len2 = num2.length();
		for(int i = 0; i < len1; i ++) {
			for(int j = 0; j < len2; j ++) {
				num[i+j] += (num1[len1-i-1]-'0')*(num2[len2-j-1]-'0');
			}
		}
		for(int i = 0; i < len1+len2-1; i ++) {
			num[i+1] += num[i]/10;
			num[i] %= 10;
		}
		int len3 = len1+len2-1;
		while(len3 > 0 && num[len3] == 0) len3--;
		string result;
		while(len3 >= 0) {
			result+=(num[len3--]+'0');
		}
		delete[] num;
		return result;
    }
};

int main() {
	Solution sol;
	cout << sol.multiply("0","456") << endl;
	return 0;
}