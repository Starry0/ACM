#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
		int cnt = 1;
		for(int i = 1; i < nums.size(); i ++) {
			if(cnt == 0) {
				cnt = 1;
				result = nums[i];
			} else if(nums[i] == result) cnt ++;
			else cnt--;
		}
		return result;
    }
};

int main() {
	Solution sol;
	vector<int> vs{2,2,1,1,1,2,2};
	cout << sol.majorityElement(vs);
	return 0;
}