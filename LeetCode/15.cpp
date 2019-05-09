#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return {};
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i ++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                if(nums[left]+nums[right] == -nums[i]) {
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right] > -nums[i]) right--;
                else left++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> vs{-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.threeSum(vs);
    for(auto X : result) {
        for(auto x : X) printf("%d ",x);
        cout << endl;
    }
    return 0;
}