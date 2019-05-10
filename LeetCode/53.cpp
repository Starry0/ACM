#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int result = nums[0];
		int MAX = nums[0];
		for(int i = 1; i < nums.size(); i ++) {
			MAX = max(nums[i], MAX+nums[i]);
			result = max(MAX, result);
		}
		return result;
    }
};

int main() {
	Solution sol;
	vector<int>vs{-2,1};
	cout << sol.maxSubArray(vs);
	return 0;
}