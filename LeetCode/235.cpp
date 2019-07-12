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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        while(true) {
        	if(root->val > p->val && root->val > q->val)
        		root = root->left;
        	else if(root->val < p->val && root->val < q->val)
        		root = root->right;
        	else break;
        }
        return root;
    }
};
int main() {
	Solution sol;

	return 0;
}