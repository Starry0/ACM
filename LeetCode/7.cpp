#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		int f = 1;
		if(x < 0) {
			f = -1;
			x *= -1;
		}
		int tmp = 0;
		while(x > 0) {
			tmp = tmp*10 + x%10;
			x /= 10;
		}
		return tmp*f;
    }
};

int main() {
	Solution sol;
	cout << sol.reverse(1534236469) << endl;
	cout << sol.reverse(-123) << endl;
	cout << sol.reverse(120) << endl;
	return 0;
}