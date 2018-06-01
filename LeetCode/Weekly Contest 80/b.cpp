#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
		bool vis[10010];
		memset(vis,0,sizeof(vis));
        for(int i = 0; i < G.size(); i ++) {
			vis[G[i]] = true;
		}
		int ans = 0, pre, flag = 0;
		ListNode *p;
		p = head;
		while(p) {
			if(!flag &&vis[p->val]) {
				ans++;
			} 
			if(!vis[p->val]) flag = false;
			else flag = true;
			p = p->next;
		}
		return ans;
    }
};

int main() {
	Solution sol;
	return 0;
}