#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		if(n <= 0) return {};
        vector<vector<int>> result(n, vector<int>(n, 0));
		int start = 1;
		int row = 0, col = 0;
		result[0][0] = start++;
		while(start <= n*n) {
			while(col+1 < n && result[row][col+1] == 0) {
				result[row][++col] = start++;
			}
			while(row+1 < n && result[row+1][col] == 0) {
				result[++row][col] = start++;
			}
			while(col-1 >= 0 && result[row][col-1] == 0) {
				result[row][--col] = start++;
			}
			while(row-1 >= 0 && result[row-1][col] == 0) {
				result[--row][col] = start++;
			}
		}
		return result;
    }
};

int main() {
	Solution sol;
	auto result = sol.generateMatrix(5);
	for(auto X : result) {
		for(auto x : X) printf("%d ",x);
		printf("\n");
	}
	return 0;
}