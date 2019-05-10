#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		if(n == 1) return 1;
		if(n == 2) return 2;
        int *fac = new int[n];
		fac[0] = 1, fac[1] = 2;
		for(int i = 2; i < n; i ++) fac[i] = fac[i-1]+fac[i-2];
		int value = fac[n-1];
		delete[] fac;
		return value;
    }
};


int main() {
	Solution sol;
	cout << sol.climbStairs(3) << endl;
	return 0;
}