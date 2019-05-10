#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if(nums.size() == 0) return 0;
        int len = 1;
		for(int i = 1; i < nums.size(); i ++) {
			if(nums[i] != nums[i-1])
				nums[len++] = nums[i];
		}
		nums.resize(len);
		return len;
    }
};

int main() {
	Solution sol;
	vector<int> vs{0,0,1,1,1,2,2,3,3,4};
	cout << sol.removeDuplicates(vs);
	return 0;
}