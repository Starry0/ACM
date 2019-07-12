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
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        kthSmallestTmp(root, k);
        return result;
    }
private:
	void kthSmallestTmp(TreeNode *root, int k) {
		if(root == NULL) return ;
        kthSmallestTmp(root->left, k);
        cnt++;
        if(cnt == k) result = root->val;
        kthSmallestTmp(root->right, k);
	}
	int cnt;
	int result;
};
int main() {
	Solution sol;
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(1);
	TreeNode *c = new TreeNode(4);
	TreeNode *d = new TreeNode(2);
	a->left = b;
	a->right = c;
	b->right = d;
	cout << sol.kthSmallest(a, 1) << endl;
	return 0;
}