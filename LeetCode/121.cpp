#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MAX = 0, minPri = INT_MAX;
		for(int i = 0; i < prices.size(); i ++) {
			minPri = min(minPri, prices[i]);
			MAX = max(MAX, prices[i]-minPri);
		}
		return MAX;
    }
};

int main() {
	Solution sol;
	vector<int> vs{7,1,5,3,6,4};
	cout << sol.maxProfit(vs);
	return 0;
}