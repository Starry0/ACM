#include <bits/stdc++.h>
using namespace std;


// O(2n)
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     	if(s.length() == 0) return 0;
//         int MAX = 1, left = 0, cnt = 0;
// 	    set<char> st;
//         for(int i = 0; i < s.length(); i ++) {
//         	if(!st.count(s[i])) {
//         		st.insert(s[i]);
//         	}else {
//         		while(left < i && s[left] != s[i]) {
//         			st.erase(s[left++]);
//         		}
//         		left++;
//         	}
//         	MAX = max(MAX, i-left+1);
//         }
//         return MAX;
//     }
// };

//O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int index[128], MAX = 0;
    	memset(index, -1, sizeof(index));
    	for(int i = 0, left = -1; i < s.length(); i ++) {
    		left = max(left, index[s[i]]);
    		MAX = max(MAX, i-left);
    		index[s[i]] = i;
    	}
    	return MAX;
    }
};

int main() {
	Solution s;
	int len = s.lengthOfLongestSubstring("pwwkew");
	cout << len << endl;
	return 0;
}