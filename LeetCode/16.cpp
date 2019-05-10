#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0]+nums[1]+nums[2];
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i ++) {
			int left = i+1, right = nums.size()-1;
			while(left < right) {
				int num = nums[i]+nums[left]+nums[right];
				if(num == target) return target;
				if(abs(num-target) < abs(result-target)) result = num;
				if(num > target) right--;
				else left++;
			}
		}
		return result;
    }
};

int main() {
	Solution sol;
	vector<int> vs{-1,2,1,-4};
	cout << sol.threeSumClosest( vs, 1);
	return 0;
}