#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        for(int right = 1; right <= s.length(); right ++) {
        	if(s[right] == ' ' || right == s.length()) {
        		swap_str(s, left, right-1);
        		left = right+1;
        	}
        }
        return s;
    }
private:
	void swap_str(string &s, int le, int ri) {
		while(le < ri) {
			swap(s[le++], s[ri--]);
		}
	}
};

int main() {
	Solution sol;

	return 0;
}