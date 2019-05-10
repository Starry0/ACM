#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = n+m-1;
		m--;n--;
		while(m >= 0 && n >= 0) {
			if(nums1[m] >= nums2[n]) {
				nums1[pos--] = nums1[m--];
			} else {
				nums1[pos--] = nums2[n--];
			}
		}
		while(m >= 0) nums1[pos--] = nums1[m--];
		while(n >= 0) nums1[pos--] = nums2[n--];
    }
};

int main() {
	Solution sol;
	vector<int> nums1{1,2,3,0,0,0};
	vector<int> nums2{2,5,6};
	sol.merge(nums1, 3, nums2, 3);
	for(auto x : nums1) {
		printf("%d ",x);
	}
	return 0;
}