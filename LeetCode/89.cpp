#include <bits/stdc++.h>
using namespace std;

/**
 * 计算大小为n的值可以同n-1得到，由于n-1是符合的，那么在计算
 * n时，只需要把第n位置为1，然后用n-1的对称就行了
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1);
		for(int i = 0; i < n; i ++) {
			int len = result.size();
			for(int j = len-1; j >= 0; -- j) {
				result.push_back(result[j]|(1<<i));
			}
		}
		return result;
    }
};

int main() {
	Solution sol;

	return 0;
}