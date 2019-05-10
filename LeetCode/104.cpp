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
    int maxDepth(TreeNode* root) {
        // if(root == NULL) return 0;
		return root==NULL? 0: max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

int main() {
	Solution sol;

	return 0;
}