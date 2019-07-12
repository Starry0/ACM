#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &x : nums) {
        	if(mp.count(x)) return true;
        	mp[x] = 1;
        }
        return false;
    }
};

int main() {
	Solution sol;

	return 0;
}