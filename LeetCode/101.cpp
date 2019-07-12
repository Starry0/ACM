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
    bool isSymmetric(TreeNode* root) {
    	if(root == NULL) return true;
       	return isSymmetric(root->left, root->right);
    }
private:
	bool isSymmetric(TreeNode* p1, TreeNode* p2) {
		if(p1 == NULL && p2 == NULL) return true;
		if(p1 == NULL || p2 == NULL) return false;
		bool flag = p1->val == p2->val;
		return flag && isSymmetric(p1->left, p2->right) && 
					isSymmetric(p1->right, p2->left);
	}
};
int main() {

	return 0;
}