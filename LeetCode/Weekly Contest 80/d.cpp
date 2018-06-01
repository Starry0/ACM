#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int racecar(int target) {
		int ans = 0;
        while(target > 0) {
			int tmp, MAX = 0x3f3f3f3f;
			for(int i = 1; i <= 14; i ++) {
				if(abs((1<<i)-1-target) < MAX) {
					MAX = abs((1<<i)-1-target);
					tmp = i;
				}
			}
			cout << tmp << ' ' << target << ' ' << MAX << endl;
			ans += tmp;
			target = MAX;
			if(target) ans++;
		}
		cout << ans << endl;
		return ans;
    }
};

int main() {
	Solution sol;
	sol.racecar(2);
	return 0;
}