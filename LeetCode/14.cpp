#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int right = strs[0].length(), j;
        for(int i = 1; i < strs.size(); i ++) {
            for(j = 0; j < strs[i].length(); j ++) {
                if(strs[0][j] != strs[i][j])
                    break;
            }
            right = min(right, j);
        }
        return strs[0].substr(0, right);
    }
};

int main() {
    Solution sol;
    vector<string> vs{"dog","racecar","car"};
    cout << sol.longestCommonPrefix(vs) << endl;
    return 0;
}