#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
// 		if(nums.size() == 0) return {};
//         vector<vector<int>> result;
// 		int len = nums.size();
// 		for(int i = 0; i < (1<<len); i ++) {
// 			vector<int> tmp;
// 			for(int j = 0; j < len; j ++) {
// 				if((i>>j)&1) tmp.push_back(nums[j]); 
// 			}
// 			result.push_back(tmp);
// 		}
// 		return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > result(1);
		for(auto &x : nums) {
			int sz = result.size();
			while(sz--) {
				result.push_back(result[sz]);
				result.back().push_back(x);
			}
		}
		return result;
    }
};

int main() {
	Solution sol;
	int a[] = {1,2,3};
	std::vector<int> v(a,a+3);
	auto result = sol.subsets(v);
	for(auto x : result) {
		for(auto y : x) cout << y << " ";
			cout << endl;
	}
	return 0;
}