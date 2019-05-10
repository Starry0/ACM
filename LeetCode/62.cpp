#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *dp = new int[n];
		memset(dp, 0, sizeof(int)*n);
		for(int i = 0; i < m; i ++) {
			for(int j = 0; j < n; j ++) {
				if(j == 0) dp[j] = 1;
				else dp[j] += dp[j-1];
			}
		}
		int value = dp[n-1];
		delete[] dp;
		return value;
    }
};

int main() {
	Solution sol;
	cout << sol.uniquePaths(3,7) << endl;
	return 0;
}