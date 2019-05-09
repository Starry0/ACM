#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;
//         char *str = new char[10];
//         int cnt = 0;
//         while(x > 0) {
//             str[cnt++] = x%10+'0';
//             x /= 10;
//         }
//         for(int i = 0; i < cnt/2; i ++) {
//             if(str[i] != str[cnt-i-1]) return false;
//         }
//         delete[] str;
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10==0 && x!=0)) return false;
        int ans = 0;
        while(x > ans) {
            ans = ans*10+x%10;
            x /= 10;
        }
        return ans==x|| ans/10 == x;
    }
};


int main() {
    Solution sol;
    cout << sol.isPalindrome(122) << endl;
    return 0;
}