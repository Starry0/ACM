#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		if(nums.size() == 0 || k > nums.size()) return -1;
        int left = 0, right = nums.size()-1; k--;
		while(left <= right) {
			int pos = find(nums, left, right);
			if(pos == k) return nums[pos];
			else if(pos > k) right = pos-1;
			else left = pos+1;
		}
		return -1;
    }
private:
	int find(vector<int>& nums, int low, int high) {
		int tmp = nums[low];
		while(low < high) {
			while(low < high && nums[high] <= tmp) high --;
			nums[low] = nums[high];
			while(low < high && nums[low] >= tmp) low ++;
			nums[high] = nums[low];
		}
		nums[low] = tmp;
		return low;
	}
};

int main() {
	Solution sol;
	vector<int> vs{3,2,3,1,2,4,5,5,6};
	cout << sol.findKthLargest(vs, 4);
	return 0;
}