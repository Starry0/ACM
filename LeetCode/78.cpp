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
		if(nums.size() == 0) return {};
        vector<vector<int>> result(1);
		for(int i = 0; i < nums.size(); i ++ ) {
			int len = result.size();
			for(int j = 0; j < len; j ++) {
				result.push_back(result[j]);
				result.back().push_back(nums[i]);
			}
		}
		return result;
    }
};

int main() {
	Solution sol;

	return 0;
}