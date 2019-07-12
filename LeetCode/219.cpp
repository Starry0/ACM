#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	if(nums.empty()) return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i ++) {
        	if(mp.count(nums[i])) {
        		if(i-mp[nums[i]] <= k) return true;
        		else mp[nums[i]] = i;
        	} else mp[nums[i]] = i;
        }
        return false;
    }
};

int main() {
	Solution sol;

	return 0;
}