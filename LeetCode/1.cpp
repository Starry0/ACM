#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int> &nums, int target) 
    {
        vector<int> result;
        int N = nums.size();
        for (int i = 0; i < N; i++) 
        {
            for (int j = i+1; j < N; j++) 
            {
                if (nums[i] + nums[j] == target) 
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
	vector<int> vs, vs1;
	int x, tar, n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		vs.push_back(x);
	}
	cin >> tar;
	Solution Sol;
	vs1 = Sol.twoSum(vs,tar);
	for(int i = 0; i < 2; i ++) {
		cout << vs1[i] << endl;
	}
	return 0;
}