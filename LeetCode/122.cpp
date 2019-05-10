#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size() == 0) return 0;
        int sum = 0, left = 0;
		for(int i = 1; i < prices.size(); i ++) {
			if(prices[i] < prices[i-1]) {
				sum += prices[i-1]-prices[left];
				left = i;
			}
		}
		sum += max(0, prices.back()-prices[left]);
		return sum;
    }
};

int main() {
	Solution sol;
	vector<int> vs{6,1,3,2,4,7};
	cout << sol.maxProfit(vs);
	return 0;
}