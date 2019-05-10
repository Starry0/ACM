#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if(matrix.size() == 0) return {};
        vector<int> result;
		int rows = matrix.size(), cols = matrix[0].size();
		int start = 0;
		while(start*2 < cols && start*2 < rows) {
			circle(result, start, rows, cols, matrix);
			++start;
		}

		return result;
    }
private:
	void circle(vector<int> &result, int start, int rows, int cols, vector<vector<int>>& matrix) {
		int endX = rows-start-1, endY = cols-start-1;
		for(int i = start; i <= endY; i ++) {
			result.push_back(matrix[start][i]);
		}
		for(int i = start+1; i <= endX; i ++) {
			result.push_back(matrix[i][endY]);
		}
		if(endX > start) {
			for(int i = endY-1; i >= start; i --) {
				result.push_back(matrix[endX][i]);
			}
		}
		if(start < endY) {
			for(int i = endX-1; i >= start+1; i --) {
				result.push_back(matrix[i][start]);
			}
		}
	}
};

int main() {
	Solution sol;
	
	return 0;
}