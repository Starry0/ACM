#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int pos1 = (n+m+1)/2, pos2 = (n+m+2)/2;
        int left = 0, right = n-1, mid, mid2;
        while(left <= right) {
        	mid = (left+right)>>1;
        	mid2 = upper_bound(nums2.begin(),nums2.end(),nums1[mid])-nums2.begin();
        	int tmp = mid+mid2+1;
            if(tmp == pos1 || tmp == pos2) break;
            if(tmp < pos1) left = mid+1;
            else right = mid-1;
        }
        if(pos1 == pos2) return
        return 1;
    }
};

int main() {
	Solution s;
	vector<int> v,v1;
	v.push_back(1);
	v.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	cout << s.findMedianSortedArrays(v, v1);

	return 0;
}