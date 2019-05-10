#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int result = 0;
		for(auto x : nums) result ^= x;
		return result;
    }
};

int main() {
	Solution sol;

	return 0;
}