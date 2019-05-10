#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return {};
		vector<vector<int>> result;
		permute(result, nums, 0);
		return result;
    }
private:
	void permute(vector<vector<int>>&result, vector<int> nums, int begin) {
		if(begin == nums.size()) {
			result.push_back(nums);
			return;
		}
		for(int i = begin; i < nums.size(); i ++) {
			swap(nums[i], nums[begin]);
			permute(result, nums, begin+1);
			swap(nums[i], nums[begin]);
		}
	}
};

int main() {
	Solution sol;
	vector<int> vs{1,2,3,4};
	auto result = sol.permute(vs);
	for(auto X : result) {
		for(auto x : X) printf("%d ",x);
		printf("\n");
	}
	return 0;
}