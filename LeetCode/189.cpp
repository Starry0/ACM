#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//     	int len = nums.size();
//     	k %= len;
//         swapArray(nums, 0, len-k-1);
//         swapArray(nums, len-k, len-1);
//         swapArray(nums, 0, len-1);
//     }
// private:
// 	void swapArray(vector<int> &nums, int s, int t) {
// 		while(s < t) swap(nums[s++], nums[t--]);
// 	}
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	int len = nums.size();
    	k %= len;
    	int cnt = 0;
        for(int start = 0; cnt < len; start ++) {
			int current = start, preVal = nums[start];
			do{
				int next = (current+k)%len;
				int tmp = nums[next];
				nums[next] = preVal;
				preVal = tmp;
				current = next;
				cnt++;
			}while(current != start);     	
        }
    }
};

int main() {
	Solution sol;
	std::vector<int> v{1,2,3,4,5,6,7};

	return 0;
}