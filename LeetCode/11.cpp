#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int MAX = 0;
        while(left < right) {
            MAX = max(MAX, (right - left)*min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return MAX;
    }
};

int main() {
    Solution sol;
    vector<int> vs{1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(vs) << endl;
    return 0;
}