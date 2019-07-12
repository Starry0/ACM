#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
    	int len = s.size();
        for(int i = 0; i < len/2; i ++) {
        	s[i] ^= s[len-i-1];
        	s[len-i-1] = s[i]^s[len-i-1];
        	s[i] = s[i]^s[len-i-1];
        }
    }
};
int main() {
	Solution sol;

	return 0;
}