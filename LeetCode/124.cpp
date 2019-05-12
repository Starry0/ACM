#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        getMax(root);
		return MAX;
    }
private:
	int getMax(TreeNode* root) {
		if(root == NULL) return 0;
		int left = max(0, getMax(root->left));
		int right = max(0, getMax(root->right));
		MAX = max(MAX, root->val+left+right);
		return max(left, right) + root->val;
	}
	int MAX = INT_MIN;
};
int main() {
	Solution s;

	return 0;
}