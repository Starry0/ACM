#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//不能使用除法
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        vector<int> pre(nums.size()+1), sum(nums.size()+1);
        sum[0] = 1;
        for(int i = 0; i < nums.size(); i ++) {
        	sum[i+1] = sum[i]*nums[i];
        }
        pre[nums.size()] = 1;
        for(int i = nums.size()-1; i >= 0; i --) {
        	pre[i] = pre[i+1]*nums[i];
        }
        for(int i = 0; i < nums.size(); i ++) {
        	result.push_back(sum[i]*pre[i+1]);
        }
        return result;
    }
};

int main() {
	Solution sol;
	int a[] = {1,2,3,4};
	vector<int> A(a, a+4);
	auto result = sol.productExceptSelf(A);
	for(auto &x : result) {
		cout << x << ' ';
	}
	return 0;
}