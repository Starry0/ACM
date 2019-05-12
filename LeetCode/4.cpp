#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0) return 0;
		int len1 = nums1.size(), len2 = nums2.size();
		int l = (len1+len2+1)/2;
		int r = (len1+len2+2)/2;
		if(l == r) return getKth(nums1, 0, nums2, 0, l);
		else return (getKth(nums1, 0, nums2, 0, l)+getKth(nums1, 0, nums2, 0, r)) / 2.0;
    }
private:
	int getKth(vector<int>& nums1, int pos1, vector<int>& nums2, int pos2, int k) {
		if(pos1 >= nums1.size()) return nums2[pos2+k-1];
		if(pos2 >= nums2.size()) return nums1[pos1+k-1];
		if(k == 1) return min(nums1[pos1], nums2[pos2]);
		int mid1 = INT_MAX, mid2 = INT_MAX;
		if(pos1+k/2 <= nums1.size()) mid1 = nums1[pos1+k/2-1];
		if(pos2+k/2 <= nums2.size()) mid2 = nums2[pos2+k/2-1];
		if(mid1 < mid2) 
			return getKth(nums1, pos1+k/2, nums2, pos2, k-k/2);
		else 
			return getKth(nums1, pos1, nums2, pos2+k/2, k-k/2);
	}
};

int main() {
	Solution s;
	vector<int> v,v1;
	v.push_back(1);
	v.push_back(2);
	//v1.push_back(3);
	v1.push_back(4);
	cout << s.findMedianSortedArrays(v, v1);

	return 0;
}