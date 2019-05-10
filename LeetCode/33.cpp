#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
		while(left <= right) {
			int mid = (left + right) >> 1;
			if(nums[mid] == target) return mid;
			if(nums[mid] >= nums[left]) {
				if(nums[left] <= target && target < nums[mid]) right = mid-1;
				else left = mid+1;
			} else if(nums[mid] <= nums[right]) {
				if(nums[right] >= target && target > nums[mid]) left = mid+1;
				else right = mid-1; 
			}
		}
		return -1;
    }
};

int main() {
	Solution sol;
	vector<int> vs{3,1};
	cout << sol.search(vs, 1);
	return 0;
}