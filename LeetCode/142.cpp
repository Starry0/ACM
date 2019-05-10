#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pNode = hasCycle(head);
		if(pNode == NULL) return NULL;
		ListNode* pNodeTwo = pNode;
		int len = 1;
		while(pNodeTwo->next != pNode) {
			pNodeTwo = pNodeTwo->next;
			len++;
		}
		pNode = pNodeTwo = head;
		int cnt = len;
		while(cnt-- > 0) {
			pNode = pNode->next;
		}
		while(pNode != pNodeTwo) {
			pNode = pNode->next;
			pNodeTwo = pNodeTwo->next;
		}
		return pNodeTwo;
    }
private:
	ListNode *hasCycle(ListNode *head) {
		if(head == NULL) return NULL;
		ListNode* pNode = head, *pNodeTwo = head;
		while(pNodeTwo->next != NULL) {
			pNode = pNode->next;
			pNodeTwo = pNodeTwo->next;
			if(pNodeTwo->next != NULL) pNodeTwo = pNodeTwo->next;
			else return NULL;
			if(pNode == pNodeTwo) return pNode;
		}
		return NULL;
	}
};

int main() {
	Solution sol;
	ListNode *p1 = new ListNode(3);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(0);
	ListNode *p4 = new ListNode(-4);
	p1->next = p2;p2->next = p3;
	p3->next = p4;p4->next = p2;
	ListNode *pNode = sol.detectCycle(p1);
	if(pNode != NULL) cout << pNode->val << endl;
	else cout << "NO\n";
	return 0;
}