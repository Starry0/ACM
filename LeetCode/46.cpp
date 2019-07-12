#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<vector<int>> result;
        permute(result, nums, 0);
        return result;
    }
private:
	void permute(vector<vector<int>> &result, vector<int> nums, int pos) {
		if(pos == nums.size()) {
			result.push_back(nums);
			return;
		}
		for(int i = pos; i < nums.size(); i ++) {
			swap(nums[i], nums[pos]);
			permute(result, nums, pos+1);
			swap(nums[i], nums[pos]);
		}
	}
};

int main() {
	Solution sol;
	vector<int> vs{1,2,3};
	auto result = sol.permute(vs);
	for(auto X : result) {
		for(auto x : X) printf("%d ",x);
		printf("\n");
	}
	return 0;
}